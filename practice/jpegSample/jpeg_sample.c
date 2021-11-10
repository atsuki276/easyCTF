#include <stdio.h>
#include <stdlib.h>
#include <C:/jpeg-9d/jpeglib.h>

int main () {
    /* JPEGオブジェクト, エラーハンドラの確保 */
    struct jpeg_compress_struct cinfo;
    struct jpeg_error_mgr jerr;

    /* エラーハンドラにデフォルト値を設定 */
    cinfo.err = jpeg_std_error(&jerr);

    /* JPEGオブジェクトの初期化 */
    jpeg_create_compress(&cinfo);

    /* 出力ファイルの設定 */
    char *filename = "image.jpg";
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        fprintf(stderr, "cannot open %s\n", filename);
        exit(EXIT_FAILURE);
    }
    jpeg_stdio_dest(&cinfo, fp);

    /* 画像のパラメータの設定 */
    int width = 256;
    int height = 256;

    cinfo.image_width = width;
    cinfo.image_height = height;
    cinfo.input_components = 3;
    cinfo.in_color_space = JCS_RGB;
    jpeg_set_defaults(&cinfo);
    jpeg_set_quality(&cinfo, 75, TRUE);

    /* 圧縮開始 */
    jpeg_start_compress(&cinfo, TRUE);

    /* RGB値の設定 */
    JSAMPARRAY img = (JSAMPARRAY) malloc(sizeof(JSAMPROW) * height);
    for (int i = 0; i < height; i++) {
        img[i] = (JSAMPROW) malloc(sizeof(JSAMPLE) * 3 * width);
        for (int j = 0; j < width; j++) {
            img[i][j*3 + 0] = i;
            img[i][j*3 + 1] = j;
            img[i][j*3 + 2] = 127;
        }
    }
    /* 書き込む */
    jpeg_write_scanlines(&cinfo, img, height);

    /* 圧縮終了 */
    jpeg_finish_compress(&cinfo);

    /* JPEGオブジェクトの破棄 */
    jpeg_destroy_compress(&cinfo);

    for (int i = 0; i < height; i++) {
        free(img[i]);
    }
    free(img);
    fclose(fp);
}