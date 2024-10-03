/**
 * @file    moc_audio.h
 * @brief   A simple and naive sine wave generator for creating mock audio is represented here.
 * @details This is a "cheap and cheerful" module. No attempts are made at generating a perfect sine, just something
 * good enough to use for mock SD card writes for testing. The idea is to write a sine wave of a chosen sample rate and
 * frequency to the SD card so we can validate that the audio on the card matches our intention.
 */

#ifndef MOCK_AUDIO_H_
#define MOCK_AUDIO_H_

#include <stdint.h>

/* Public function declarations --------------------------------------------------------------------------------------*/

/**
 * @brief `mock_audio_sine_init()` initializes the internal sine wave generator.
 *
 * @post the sine generator is ready to be used.
 */
void mock_audio_sine_init();

/**
 * @brief `mock_audio_set_sample_rate(sr)` sets the sample rate used by the sine generator.
 *
 * @param sr_Hz The sample rate to use, in Hertz.
 */
void mock_audio_set_sample_rate(uint32_t sr_Hz);

/**
 * @brief `mock_audio_set_sine_freq(f)` sets the frequency of the sine generator to `f` Hertz.
 *
 * @param freq_Hz the frequency of the sine wave generated by future calls to tick. Note that if the frequency
 * meets or exceeds the configured (sample rate / 2), aliasign will occur.
 */
void mock_audio_set_sine_freq(uint32_t freq_Hz);

/**
 * @brief `mock_audio_sine_tick()` ticks the sine wave one sample forward and returns the current sample.
 *
 * @pre `mock_audio_sine_init()` has been called.
 *
 * @post the sine generator is advanced by one tick given by the currently set sample rate and frequency.
 *
 * @return the current value of the sine generator.
 */
int16_t mock_audio_sine_tick();

#endif /* MOCK_AUDIO_H_ */
