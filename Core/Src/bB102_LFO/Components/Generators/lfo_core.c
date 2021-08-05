/*
 * oscillator_core.c
 *
 *  Created on: Jun 11, 2021
 *      Author: fil
 */

#include "main.h"
#if WAVETABLE_SIZE == 256
__attribute__((section(".table"))) const int16_t        sinetab[WAVETABLE_SIZE] = {
		0x0,0x1,0x2,0x6,0xa,0xf,0x16,0x1e,
		0x27,0x32,0x3d,0x4a,0x58,0x67,0x78,0x89,
		0x9c,0xb0,0xc5,0xdb,0xf2,0x10a,0x123,0x13e,
		0x159,0x175,0x193,0x1b1,0x1d1,0x1f1,0x212,0x235,
		0x258,0x27c,0x2a0,0x2c6,0x2ed,0x314,0x33c,0x365,
		0x38e,0x3b8,0x3e3,0x40e,0x43a,0x467,0x494,0x4c2,
		0x4f0,0x51f,0x54e,0x57d,0x5ad,0x5dd,0x60e,0x63f,
		0x670,0x6a1,0x6d3,0x705,0x737,0x769,0x79b,0x7cd,
		0x800,0x832,0x864,0x896,0x8c8,0x8fa,0x92c,0x95e,
		0x98f,0x9c0,0x9f1,0xa22,0xa52,0xa82,0xab1,0xae0,
		0xb0f,0xb3d,0xb6b,0xb98,0xbc5,0xbf1,0xc1c,0xc47,
		0xc71,0xc9a,0xcc3,0xceb,0xd12,0xd39,0xd5f,0xd83,
		0xda7,0xdca,0xded,0xe0e,0xe2e,0xe4e,0xe6c,0xe8a,
		0xea6,0xec1,0xedc,0xef5,0xf0d,0xf24,0xf3a,0xf4f,
		0xf63,0xf76,0xf87,0xf98,0xfa7,0xfb5,0xfc2,0xfcd,
		0xfd8,0xfe1,0xfe9,0xff0,0xff5,0xff9,0xffd,0xffe,
		0xfff,0xffe,0xffd,0xff9,0xff5,0xff0,0xfe9,0xfe1,
		0xfd8,0xfcd,0xfc2,0xfb5,0xfa7,0xf98,0xf87,0xf76,
		0xf63,0xf4f,0xf3a,0xf24,0xf0d,0xef5,0xedc,0xec1,
		0xea6,0xe8a,0xe6c,0xe4e,0xe2e,0xe0e,0xded,0xdca,
		0xda7,0xd83,0xd5f,0xd39,0xd12,0xceb,0xcc3,0xc9a,
		0xc71,0xc47,0xc1c,0xbf1,0xbc5,0xb98,0xb6b,0xb3d,
		0xb0f,0xae0,0xab1,0xa82,0xa52,0xa22,0x9f1,0x9c0,
		0x98f,0x95e,0x92c,0x8fa,0x8c8,0x896,0x864,0x832,
		0x800,0x7cd,0x79b,0x769,0x737,0x705,0x6d3,0x6a1,
		0x670,0x63f,0x60e,0x5dd,0x5ad,0x57d,0x54e,0x51f,
		0x4f0,0x4c2,0x494,0x467,0x43a,0x40e,0x3e3,0x3b8,
		0x38e,0x365,0x33c,0x314,0x2ed,0x2c6,0x2a0,0x27c,
		0x258,0x235,0x212,0x1f1,0x1d1,0x1b1,0x193,0x175,
		0x159,0x13e,0x123,0x10a,0xf2,0xdb,0xc5,0xb0,
		0x9c,0x89,0x78,0x67,0x58,0x4a,0x3d,0x32,
		0x27,0x1e,0x16,0xf,0xa,0x6,0x2,0x1,
};
#endif
#if WAVETABLE_SIZE == 1024
__attribute__((section(".table"))) const int16_t        sinetab[WAVETABLE_SIZE] = {
0x800,0x80c,0x819,0x825,0x832,0x83e,0x84b,0x857,
0x864,0x871,0x87d,0x88a,0x896,0x8a3,0x8af,0x8bc,
0x8c8,0x8d5,0x8e1,0x8ee,0x8fa,0x907,0x913,0x91f,
0x92c,0x938,0x945,0x951,0x95e,0x96a,0x976,0x983,
0x98f,0x99b,0x9a8,0x9b4,0x9c0,0x9cc,0x9d9,0x9e5,
0x9f1,0x9fd,0xa09,0xa15,0xa22,0xa2e,0xa3a,0xa46,
0xa52,0xa5e,0xa6a,0xa76,0xa82,0xa8e,0xa9a,0xaa5,
0xab1,0xabd,0xac9,0xad5,0xae0,0xaec,0xaf8,0xb03,
0xb0f,0xb1b,0xb26,0xb32,0xb3d,0xb49,0xb54,0xb60,
0xb6b,0xb76,0xb82,0xb8d,0xb98,0xba3,0xbae,0xbba,
0xbc5,0xbd0,0xbdb,0xbe6,0xbf1,0xbfc,0xc06,0xc11,
0xc1c,0xc27,0xc32,0xc3c,0xc47,0xc52,0xc5c,0xc67,
0xc71,0xc7b,0xc86,0xc90,0xc9a,0xca5,0xcaf,0xcb9,
0xcc3,0xccd,0xcd7,0xce1,0xceb,0xcf5,0xcff,0xd09,
0xd12,0xd1c,0xd26,0xd2f,0xd39,0xd42,0xd4c,0xd55,
0xd5f,0xd68,0xd71,0xd7a,0xd83,0xd8c,0xd95,0xd9e,
0xda7,0xdb0,0xdb9,0xdc2,0xdca,0xdd3,0xddc,0xde4,
0xded,0xdf5,0xdfd,0xe06,0xe0e,0xe16,0xe1e,0xe26,
0xe2e,0xe36,0xe3e,0xe46,0xe4e,0xe55,0xe5d,0xe65,
0xe6c,0xe74,0xe7b,0xe82,0xe8a,0xe91,0xe98,0xe9f,
0xea6,0xead,0xeb4,0xebb,0xec1,0xec8,0xecf,0xed5,
0xedc,0xee2,0xee8,0xeef,0xef5,0xefb,0xf01,0xf07,
0xf0d,0xf13,0xf19,0xf1f,0xf24,0xf2a,0xf30,0xf35,
0xf3a,0xf40,0xf45,0xf4a,0xf4f,0xf54,0xf59,0xf5e,
0xf63,0xf68,0xf6d,0xf71,0xf76,0xf7a,0xf7f,0xf83,
0xf87,0xf8c,0xf90,0xf94,0xf98,0xf9c,0xf9f,0xfa3,
0xfa7,0xfaa,0xfae,0xfb1,0xfb5,0xfb8,0xfbb,0xfbf,
0xfc2,0xfc5,0xfc8,0xfca,0xfcd,0xfd0,0xfd3,0xfd5,
0xfd8,0xfda,0xfdc,0xfdf,0xfe1,0xfe3,0xfe5,0xfe7,
0xfe9,0xfeb,0xfec,0xfee,0xff0,0xff1,0xff3,0xff4,
0xff5,0xff6,0xff7,0xff8,0xff9,0xffa,0xffb,0xffc,
0xffd,0xffd,0xffe,0xffe,0xffe,0xfff,0xfff,0xfff,
0xfff,0xfff,0xfff,0xfff,0xffe,0xffe,0xffe,0xffd,
0xffd,0xffc,0xffb,0xffa,0xff9,0xff8,0xff7,0xff6,
0xff5,0xff4,0xff3,0xff1,0xff0,0xfee,0xfec,0xfeb,
0xfe9,0xfe7,0xfe5,0xfe3,0xfe1,0xfdf,0xfdc,0xfda,
0xfd8,0xfd5,0xfd3,0xfd0,0xfcd,0xfca,0xfc8,0xfc5,
0xfc2,0xfbf,0xfbb,0xfb8,0xfb5,0xfb1,0xfae,0xfaa,
0xfa7,0xfa3,0xf9f,0xf9c,0xf98,0xf94,0xf90,0xf8c,
0xf87,0xf83,0xf7f,0xf7a,0xf76,0xf71,0xf6d,0xf68,
0xf63,0xf5e,0xf59,0xf54,0xf4f,0xf4a,0xf45,0xf40,
0xf3a,0xf35,0xf30,0xf2a,0xf24,0xf1f,0xf19,0xf13,
0xf0d,0xf07,0xf01,0xefb,0xef5,0xeef,0xee8,0xee2,
0xedc,0xed5,0xecf,0xec8,0xec1,0xebb,0xeb4,0xead,
0xea6,0xe9f,0xe98,0xe91,0xe8a,0xe82,0xe7b,0xe74,
0xe6c,0xe65,0xe5d,0xe55,0xe4e,0xe46,0xe3e,0xe36,
0xe2e,0xe26,0xe1e,0xe16,0xe0e,0xe06,0xdfd,0xdf5,
0xded,0xde4,0xddc,0xdd3,0xdca,0xdc2,0xdb9,0xdb0,
0xda7,0xd9e,0xd95,0xd8c,0xd83,0xd7a,0xd71,0xd68,
0xd5f,0xd55,0xd4c,0xd42,0xd39,0xd2f,0xd26,0xd1c,
0xd12,0xd09,0xcff,0xcf5,0xceb,0xce1,0xcd7,0xccd,
0xcc3,0xcb9,0xcaf,0xca5,0xc9a,0xc90,0xc86,0xc7b,
0xc71,0xc67,0xc5c,0xc52,0xc47,0xc3c,0xc32,0xc27,
0xc1c,0xc11,0xc06,0xbfc,0xbf1,0xbe6,0xbdb,0xbd0,
0xbc5,0xbba,0xbae,0xba3,0xb98,0xb8d,0xb82,0xb76,
0xb6b,0xb60,0xb54,0xb49,0xb3d,0xb32,0xb26,0xb1b,
0xb0f,0xb03,0xaf8,0xaec,0xae0,0xad5,0xac9,0xabd,
0xab1,0xaa5,0xa9a,0xa8e,0xa82,0xa76,0xa6a,0xa5e,
0xa52,0xa46,0xa3a,0xa2e,0xa22,0xa15,0xa09,0x9fd,
0x9f1,0x9e5,0x9d9,0x9cc,0x9c0,0x9b4,0x9a8,0x99b,
0x98f,0x983,0x976,0x96a,0x95e,0x951,0x945,0x938,
0x92c,0x91f,0x913,0x907,0x8fa,0x8ee,0x8e1,0x8d5,
0x8c8,0x8bc,0x8af,0x8a3,0x896,0x88a,0x87d,0x871,
0x864,0x857,0x84b,0x83e,0x832,0x825,0x819,0x80c,
0x800,0x7f3,0x7e6,0x7da,0x7cd,0x7c1,0x7b4,0x7a8,
0x79b,0x78e,0x782,0x775,0x769,0x75c,0x750,0x743,
0x737,0x72a,0x71e,0x711,0x705,0x6f8,0x6ec,0x6e0,
0x6d3,0x6c7,0x6ba,0x6ae,0x6a1,0x695,0x689,0x67c,
0x670,0x664,0x657,0x64b,0x63f,0x633,0x626,0x61a,
0x60e,0x602,0x5f6,0x5ea,0x5dd,0x5d1,0x5c5,0x5b9,
0x5ad,0x5a1,0x595,0x589,0x57d,0x571,0x565,0x55a,
0x54e,0x542,0x536,0x52a,0x51f,0x513,0x507,0x4fc,
0x4f0,0x4e4,0x4d9,0x4cd,0x4c2,0x4b6,0x4ab,0x49f,
0x494,0x489,0x47d,0x472,0x467,0x45c,0x451,0x445,
0x43a,0x42f,0x424,0x419,0x40e,0x403,0x3f9,0x3ee,
0x3e3,0x3d8,0x3cd,0x3c3,0x3b8,0x3ad,0x3a3,0x398,
0x38e,0x384,0x379,0x36f,0x365,0x35a,0x350,0x346,
0x33c,0x332,0x328,0x31e,0x314,0x30a,0x300,0x2f6,
0x2ed,0x2e3,0x2d9,0x2d0,0x2c6,0x2bd,0x2b3,0x2aa,
0x2a0,0x297,0x28e,0x285,0x27c,0x273,0x26a,0x261,
0x258,0x24f,0x246,0x23d,0x235,0x22c,0x223,0x21b,
0x212,0x20a,0x202,0x1f9,0x1f1,0x1e9,0x1e1,0x1d9,
0x1d1,0x1c9,0x1c1,0x1b9,0x1b1,0x1aa,0x1a2,0x19a,
0x193,0x18b,0x184,0x17d,0x175,0x16e,0x167,0x160,
0x159,0x152,0x14b,0x144,0x13e,0x137,0x130,0x12a,
0x123,0x11d,0x117,0x110,0x10a,0x104,0xfe,0xf8,
0xf2,0xec,0xe6,0xe0,0xdb,0xd5,0xcf,0xca,
0xc5,0xbf,0xba,0xb5,0xb0,0xab,0xa6,0xa1,
0x9c,0x97,0x92,0x8e,0x89,0x85,0x80,0x7c,
0x78,0x73,0x6f,0x6b,0x67,0x63,0x60,0x5c,
0x58,0x55,0x51,0x4e,0x4a,0x47,0x44,0x40,
0x3d,0x3a,0x37,0x35,0x32,0x2f,0x2c,0x2a,
0x27,0x25,0x23,0x20,0x1e,0x1c,0x1a,0x18,
0x16,0x14,0x13,0x11,0xf,0xe,0xc,0xb,
0xa,0x9,0x8,0x7,0x6,0x5,0x4,0x3,
0x2,0x2,0x1,0x1,0x1,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0x1,0x1,0x1,0x2,
0x2,0x3,0x4,0x5,0x6,0x7,0x8,0x9,
0xa,0xb,0xc,0xe,0xf,0x11,0x13,0x14,
0x16,0x18,0x1a,0x1c,0x1e,0x20,0x23,0x25,
0x27,0x2a,0x2c,0x2f,0x32,0x35,0x37,0x3a,
0x3d,0x40,0x44,0x47,0x4a,0x4e,0x51,0x55,
0x58,0x5c,0x60,0x63,0x67,0x6b,0x6f,0x73,
0x78,0x7c,0x80,0x85,0x89,0x8e,0x92,0x97,
0x9c,0xa1,0xa6,0xab,0xb0,0xb5,0xba,0xbf,
0xc5,0xca,0xcf,0xd5,0xdb,0xe0,0xe6,0xec,
0xf2,0xf8,0xfe,0x104,0x10a,0x110,0x117,0x11d,
0x123,0x12a,0x130,0x137,0x13e,0x144,0x14b,0x152,
0x159,0x160,0x167,0x16e,0x175,0x17d,0x184,0x18b,
0x193,0x19a,0x1a2,0x1aa,0x1b1,0x1b9,0x1c1,0x1c9,
0x1d1,0x1d9,0x1e1,0x1e9,0x1f1,0x1f9,0x202,0x20a,
0x212,0x21b,0x223,0x22c,0x235,0x23d,0x246,0x24f,
0x258,0x261,0x26a,0x273,0x27c,0x285,0x28e,0x297,
0x2a0,0x2aa,0x2b3,0x2bd,0x2c6,0x2d0,0x2d9,0x2e3,
0x2ed,0x2f6,0x300,0x30a,0x314,0x31e,0x328,0x332,
0x33c,0x346,0x350,0x35a,0x365,0x36f,0x379,0x384,
0x38e,0x398,0x3a3,0x3ad,0x3b8,0x3c3,0x3cd,0x3d8,
0x3e3,0x3ee,0x3f9,0x403,0x40e,0x419,0x424,0x42f,
0x43a,0x445,0x451,0x45c,0x467,0x472,0x47d,0x489,
0x494,0x49f,0x4ab,0x4b6,0x4c2,0x4cd,0x4d9,0x4e4,
0x4f0,0x4fc,0x507,0x513,0x51f,0x52a,0x536,0x542,
0x54e,0x55a,0x565,0x571,0x57d,0x589,0x595,0x5a1,
0x5ad,0x5b9,0x5c5,0x5d1,0x5dd,0x5ea,0x5f6,0x602,
0x60e,0x61a,0x626,0x633,0x63f,0x64b,0x657,0x664,
0x670,0x67c,0x689,0x695,0x6a1,0x6ae,0x6ba,0x6c7,
0x6d3,0x6e0,0x6ec,0x6f8,0x705,0x711,0x71e,0x72a,
0x737,0x743,0x750,0x75c,0x769,0x775,0x782,0x78e,
0x79b,0x7a8,0x7b4,0x7c1,0x7cd,0x7da,0x7e6,0x7f3,
};
#endif
uint16_t        tritab[VOICES][WAVETABLE_SIZE];
uint16_t        squareval[VOICES];

void RunLfo(uint16_t start , uint16_t end)
{
float	delta_phase;
//float 	freq=0;
uint16_t	i;
uint16_t		angle,lfo_number;

	for ( i=start;i<end;i++)
	{
		internal_lfo_buffer[i] = 0;
		for(lfo_number=0;lfo_number<NUMLFOS;lfo_number++)
		{
			angle = (uint16_t )((Lfo[lfo_number].current_phase >> 6) & (WAVETABLE_SIZE-1));
			switch(Lfo[lfo_number].waveform)
			{
			case	SINE	:	internal_lfo_buffer[i] += (uint16_t )((float )sinetab[angle] * Lfo[lfo_number].volume);break;
			case 	TRIANGLE:	internal_lfo_buffer[i] += (uint16_t )((float )tritab[lfo_number & 0x03][angle] * Lfo[lfo_number].volume);break;
			case 	SQUARE	:
				if ( angle > squareval[lfo_number & 0x03])
					internal_lfo_buffer[i] += (uint16_t )((float )(DAC_RESOLUTION-1) * Lfo[lfo_number].volume);
				break;
			default			:	internal_lfo_buffer[i] += (uint16_t )((float )sinetab[angle] * Lfo[lfo_number].volume);break;	// SINE is default
			}
			Lfo[lfo_number].current_phase += Lfo[lfo_number].delta_phase;

			if ( LFO_FREQUENCY_POTCONTROL != 0 )
			{
				delta_phase = (float )WAVETABLE_SIZE / ((float )SystemParameters.audio_sampling_frequency*320.0F / ( float )LFO_FREQUENCY_POTCONTROL);
				Lfo[lfo_number].delta_phase = (uint16_t )(delta_phase * (float )INT_PRECISION);
			}
			else
				Lfo[lfo_number].current_phase = 0;

		}
		lfo_buffer[i] = internal_lfo_buffer[i] >> 2;
	}
	return;
}

/* phase range 0..255 for square and tri */
static void squareCompile(uint16_t	lfo_number , uint32_t phase)
{
uint16_t	k;

	k = lfo_number;
	k &= (VOICES-1);
	squareval[k] = phase;
	SystemFlags.lfo_duty[k] = phase;
}

static void triCompile(uint16_t	lfo_number , uint32_t phase)
{
float 	step_up,step_down,current;
uint16_t	i , k;

	k = lfo_number;
	k &= (VOICES-1);

	step_up = (float )(DAC_RESOLUTION-1) / (float )phase;
	step_down = (float )(DAC_RESOLUTION-1)  / (float )( WAVETABLE_SIZE - phase);
	current=0;
	for(i=0;i<WAVETABLE_SIZE;i++)
	{
		if ( i < phase )
		{
			tritab[k][i] = (uint32_t )current;
			current += step_up;
		}
		else
		{
			tritab[k][i] = (uint32_t )current;
			current -= step_down;
		}
	}
	SystemFlags.lfo_duty[k] = phase;
}

void ChangeLfoWavePhase(uint16_t	lfo_number ,	uint8_t waveform , uint16_t phase )
{
	switch (waveform)
	{
	case	TRIANGLE:	triCompile(lfo_number,phase);break;
	case	SQUARE	:	squareCompile(lfo_number,phase);break;
	default : break;
	}
}

void InitLfosTables(void)
{
uint16_t	i;
	for(i=0;i<VOICES;i++)
	{
		squareCompile(i , 127);
		triCompile(i , 127);
	}
}

