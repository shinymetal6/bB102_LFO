/*
 * oscillators.h
 *
 *  Created on: Mar 30, 2021
 *      Author: fil
 */

#ifndef INC_BB100_OSCILLATORS_H_
#define INC_BB100_OSCILLATORS_H_

#define	WAVETABLE_SIZE					1024
#define	INT_PRECISION					256
#define	INT_PRECISION_SHIFT				(INT_PRECISION >> 5)
#define	MAX_DETUNE_PERCENT_F			2.0f
#define	SINE							0
#define	TRIANGLE						1
#define	SQUARE							2

#define	OSC_OFF							0
#define	OSC_GO_OFF						1
#define	OSC_ON							2

#define	INVALID_MIDI_NOTE				0x80

enum ADSR_STATUS
{
	OSC_A_STATE,
	OSC_D_STATE,
	OSC_S_STATE,
	OSC_R_STATE,
	ADSR_CLOSE_STATE
};

#define	APPLY_TUNE				0x80

typedef struct _LfoTypeDef
{
	uint32_t 				oscillator_age;
	uint8_t 				state;
	uint8_t 				midi_note;
	uint8_t 				waveform;
	uint8_t 				adsr_state;
	uint16_t 				adsr_prescaler;
	uint16_t 				adsr_counter;
	int16_t 				a_level;
	int16_t 				d_level;
	int16_t 				s_level;
	int16_t 				r_level;
	int16_t 				a_value;
	int16_t 				d_value;
	int16_t 				a_step;
	int16_t 				d_step;
	int16_t 				r_step;
	uint16_t 				current_phase;
	uint16_t 				delta_phase;
	float 					detune;
	uint16_t 				duty;
	float 					volume;
	int16_t 				current_volume;
}LfoTypeDef;


extern	LfoTypeDef	Lfo[NUMLFOS];
extern	int16_t	wavetab[WAVETABLE_SIZE];
extern	const int16_t	sinetab[WAVETABLE_SIZE];
extern	uint32_t internal_lfo_buffer[HALF_NUMBER_OF_AUDIO_SAMPLES];
extern	uint16_t	lfo_buffer[HALF_NUMBER_OF_AUDIO_SAMPLES];

extern	void InitLfos(void);
extern	void InitLfosTables(void);
extern	void RunLfo(uint16_t start , uint16_t end);
extern	void DisableLfo(uint16_t channel, uint16_t midi_note , uint8_t velocity);
extern	void EnableLfo(uint16_t channel, uint16_t midi_note , uint8_t velocity);
extern	void ChangeLfoWavePhase(uint16_t	lfo_number ,	uint8_t waveform , uint16_t phase );
extern	void SetDetune(uint16_t lfo_number);

#endif /* INC_BB100_OSCILLATORS_H_ */
