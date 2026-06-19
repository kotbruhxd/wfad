#include "../miniaudio/miniaudio.h"


void dataCallbackStream(ma_device* pDevice, void* pOutput, const void* pInput, ma_uint32 frameCount) {
    ma_uint64 framesRead;
    ma_data_source_read_pcm_frames((ma_data_source*)pDevice->pUserData, pOutput, (ma_uint64)frameCount, &framesRead);
    (void)pInput;
}

void dataCallbackWave(ma_device *pDevice, void *pOutput, const void *pInput, ma_uint32 frameCount) {
    ma_waveform *pSineWave;
    pSineWave = (ma_waveform *)pDevice->pUserData;
    ma_uint64 framesRead;
    ma_waveform_read_pcm_frames(pSineWave, pOutput, (ma_uint64)frameCount, &framesRead);
    (void)pInput;
}

void dataCallbackNoise(ma_device *pDevice, void *pOutput, const void *pInput, ma_uint32 frameCount) {
    ma_noise *pNoise;
    pNoise = (ma_noise *)pDevice->pUserData;
    ma_uint64 framesRead;
    ma_noise_read_pcm_frames(pNoise, pOutput, (ma_uint64)frameCount, &framesRead);
    (void)pInput;
}
