#include <stdio.h>

#include "cmp_compressonatorlib/compressonator.h"

const unsigned char src[64] = { 0 };
static unsigned char dst[16] = { 0 };

CMP_Texture prepTexture(CMP_FORMAT format) {
    CMP_Texture texture = { 0 };
    texture.dwSize = sizeof(texture);
    texture.dwWidth = 1024;
    texture.dwHeight = 1024;
    texture.dwPitch = 0;
    texture.nBlockWidth = 4;
    texture.nBlockHeight = 4;
    texture.format = format;
    texture.dwDataSize = CMP_CalculateBufferSize(&texture);
    texture.pData = (CMP_BYTE*)malloc(texture.dwDataSize);
    return texture;
}

bool CompressionCallback(float fProgress, CMP_DWORD_PTR pUser1, CMP_DWORD_PTR pUser2)
{
    std::printf("\rCompression progress = %3.0f\n", fProgress);
    return false;
}

int main() {

    CMP_Texture src = prepTexture(CMP_FORMAT::CMP_FORMAT_RGBA_8888);
    CMP_Texture dst = prepTexture(CMP_FORMAT::CMP_FORMAT_ASTC);

    //==========================
    // Set Compression Options
    //==========================
    CMP_CompressOptions options = { 0 };
    options.dwSize = sizeof(options);
    options.fquality = 0.5f;
    options.dwnumThreads = 1; // Uses auto, else set number of threads from 1..127 max
    options.bDisableMultiThreading = true;

    //==========================
    // Compress Texture
    //==========================
    CMP_ERROR cmp_status;
    cmp_status = CMP_ConvertTexture(&src, &dst, &options, &CompressionCallback);

    printf("Status: %d\n", cmp_status);

    free(src.pData);
    free(dst.pData);
    return 0;
}
