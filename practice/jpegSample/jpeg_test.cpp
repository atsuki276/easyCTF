#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "jpeglib.h"

// RGB 24bit per pixel
#define IMAGE_WIDTH  1280
#define IMAGE_HEIGHT 720
#define BYTE_PER_PIXEL 3

void drawColorBar(uint8_t *imgRGB, uint32_t width, uint32_t height)
{
    for (uint32_t y = 0; y < height / 2; y++) {
        for (uint32_t x = 0; x < width / 4; x++) { *imgRGB++ = 0xFF; *imgRGB++ = 0x00; *imgRGB++ = 0x00;}
        for (uint32_t x = 0; x < width / 4; x++) { *imgRGB++ = 0x00; *imgRGB++ = 0xFF; *imgRGB++ = 0x00;}
        for (uint32_t x = 0; x < width / 4; x++) { *imgRGB++ = 0x00; *imgRGB++ = 0x00; *imgRGB++ = 0xFF;}
        for (uint32_t x = 0; x < width / 4; x++) { *imgRGB++ = 0xFF; *imgRGB++ = 0xFF; *imgRGB++ = 0xFF;}
    }
    for (uint32_t y = 0; y < height / 2; y++) {
        for (uint32_t x = 0; x < width / 4; x++) { *imgRGB++ = 0xFF; *imgRGB++ = 0xFF; *imgRGB++ = 0xFF;}
        for (uint32_t x = 0; x < width / 4; x++) { *imgRGB++ = 0x88; *imgRGB++ = 0x88; *imgRGB++ = 0x88;}
        for (uint32_t x = 0; x < width / 4; x++) { *imgRGB++ = 0x44; *imgRGB++ = 0x44; *imgRGB++ = 0x44;}
        for (uint32_t x = 0; x < width / 4; x++) { *imgRGB++ = 0x00; *imgRGB++ = 0x00; *imgRGB++ = 0x00;}
    }
}

void fileout(const char* filename, uint8_t *buf, uint32_t size)
{
    FILE *fd = fopen(filename, "wb");
    fwrite(buf, 1, size, fd);
    fclose(fd);
}

void encodeJpegFile(const char* filename, uint8_t *imgRGB, uint32_t width, uint32_t height)
{
    JSAMPROW lineBuffer[1] = {0};

    struct jpeg_compress_struct cinfo;
    struct jpeg_error_mgr jerr;
    cinfo.err = jpeg_std_error(&jerr);
    jpeg_create_compress(&cinfo);

    FILE *fd = fopen(filename, "wb");
    jpeg_stdio_dest(&cinfo, fd);

    cinfo.image_width = width;
    cinfo.image_height = height;
    cinfo.input_components = BYTE_PER_PIXEL;
    cinfo.in_color_space = JCS_RGB;
    jpeg_set_defaults(&cinfo);
    // jpeg_set_quality(&cinfo, 10, TRUE);
    jpeg_start_compress(&cinfo, TRUE);
    for (uint32_t y = 0; y < height; y++) {
        lineBuffer[0] = imgRGB;
        jpeg_write_scanlines(&cinfo, lineBuffer, 1);
        imgRGB += width * BYTE_PER_PIXEL;
    }
    jpeg_finish_compress(&cinfo);
    fclose(fd);
    jpeg_destroy_compress(&cinfo);
}

int encodeJpegMem(uint8_t *imgJpeg, uint8_t *imgRGB, uint32_t width, uint32_t height, uint32_t imgJpegSize)
{
    JSAMPROW lineBuffer[1] = {0};

    struct jpeg_compress_struct cinfo;
    struct jpeg_error_mgr jerr;
    cinfo.err = jpeg_std_error(&jerr);
    jpeg_create_compress(&cinfo);

    unsigned long writtenSize = imgJpegSize;
    //jpeg_mem_dest(&cinfo, &imgJpeg, &writtenSize);

    cinfo.image_width = width;
    cinfo.image_height = height;
    cinfo.input_components = BYTE_PER_PIXEL;
    cinfo.in_color_space = JCS_RGB;
    jpeg_set_defaults(&cinfo);
    // jpeg_set_quality(&cinfo, 10, TRUE);
    jpeg_start_compress(&cinfo, TRUE);
    for (uint32_t y = 0; y < height; y++) {
        lineBuffer[0] = imgRGB;
        imgRGB += width * BYTE_PER_PIXEL;
        jpeg_write_scanlines(&cinfo, lineBuffer, 1);
    }
    jpeg_finish_compress(&cinfo);
    jpeg_destroy_compress(&cinfo);

    return (imgJpegSize - cinfo.dest->free_in_buffer);
}

int main()
{
    printf("Hello \n");

    /* 元画像 (1280 x 720 x RGB(24bit))を用意してカラーバーを描画する */
    static uint8_t s_imageRGB[IMAGE_WIDTH * IMAGE_HEIGHT * BYTE_PER_PIXEL];
    drawColorBar(s_imageRGB, IMAGE_WIDTH, IMAGE_HEIGHT);

    /* JPEGファイル出力のテスト */
    encodeJpegFile("test.jpg", s_imageRGB, IMAGE_WIDTH, IMAGE_HEIGHT);

    /* JPEGメモリ出力のテスト */
    static uint8_t s_imageJEPG[IMAGE_WIDTH * IMAGE_HEIGHT / 2];
    uint32_t jpegSize;
    jpegSize = encodeJpegMem(s_imageJEPG, s_imageRGB, IMAGE_WIDTH, IMAGE_HEIGHT, IMAGE_WIDTH * IMAGE_HEIGHT / 2);
    fileout("testmem.jpg", s_imageJEPG, jpegSize);

    return 0;
}