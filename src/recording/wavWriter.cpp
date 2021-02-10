//
//  wavWriter.cpp
//  ofxSoundRecording
//
//  Created by keita miyano on 2021/02/09.
//

#include "wavWriter.hpp"

wavWriter::wavWriter(int fs, int bits) {
    this->fs = fs;
    this->bits = bits;
}

void wavWriter::wave_write(vector<float> data, string filenameStr) {
    //変数宣言
    FILE *fp;
    int n;
    char header_ID[4];
    long header_size;
    char header_type[4];
    char fmt_ID[4];
    long fmt_size;
    short fmt_format;
    short fmt_channel;
    long fmt_samples_per_sec;
    long fmt_bytes_per_sec;
    short fmt_block_size;
    short fmt_bits_per_sample;
    char data_ID[4];
    long data_size;
    short data_data;
    //ファイルオープン
    filenameStr = "../../../data/" + filenameStr;
    const char* filename = filenameStr.c_str();
    fp = fopen(filename, "wb");
    //ヘッダー書き込み
    header_ID[0] = 'R';
    header_ID[1] = 'I';
    header_ID[2] = 'F';
    header_ID[3] = 'F';
    header_size = 36 + data.size() * 2;
    header_type[0] = 'W';
    header_type[1] = 'A';
    header_type[2] = 'V';
    header_type[3] = 'E';
    fwrite(header_ID, 1, 4, fp);
    fwrite(&header_size, 4, 1, fp);
    fwrite(header_type, 1, 4, fp);
    //フォーマット書き込み
    fmt_ID[0] = 'f';
    fmt_ID[1] = 'm';
    fmt_ID[2] = 't';
    fmt_ID[3] = ' ';
    fmt_size = 16;
    fmt_format = 1;
    fmt_channel = 1;
    fmt_samples_per_sec = fs;
    fmt_bytes_per_sec = fs * bits / 8;
    fmt_block_size = bits / 8;
    fmt_bits_per_sample = bits;
    fwrite(fmt_ID, 1, 4, fp);
    fwrite(&fmt_size, 4, 1, fp);
    fwrite(&fmt_format, 2, 1, fp);
    fwrite(&fmt_channel, 2, 1, fp);
    fwrite(&fmt_samples_per_sec, 4, 1, fp);
    fwrite(&fmt_bytes_per_sec, 4, 1, fp);
    fwrite(&fmt_block_size, 2, 1, fp);
    fwrite(&fmt_bits_per_sample, 2, 1, fp);
    //データ書き込み
    data_ID[0] = 'd';
    data_ID[1] = 'a';
    data_ID[2] = 't';
    data_ID[3] = 'a';
    data_size = data.size() * 2;
    fwrite(data_ID, 1, 4, fp);
    fwrite(&data_size, 4, 1, fp);
    //音声データ書き込み
    for (n = 0; n < data.size(); n++) {
        //リミッター
        if (data[n] > 1) {
            data_data = 32767;
        } else if (data[n] < -1) {
            data_data = -32767;
        } else {
            data_data = (short)(data[n] * 32767.0);
        }
        fwrite(&data_data, 2, 1, fp);
    }
    fclose(fp);
}
