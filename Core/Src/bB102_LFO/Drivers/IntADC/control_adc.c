/*
 * control_adc.c
 *
 *  Created on: Jun 29, 2021
 *      Author: fil
 */

#include "main.h"

static void draw_led(void)
{
	SystemFlags.led_counter++;
	if ( SystemFlags.led_counter > SYSTICK_LEDCNTR_HALF )
	{
		ST7735_FillRectangle(1, 1, 4, 4, ST7735_RED);
		ST7735_DrawPixel(1, 1, ST7735_BLACK);
		ST7735_DrawPixel(4, 1, ST7735_BLACK);
		ST7735_DrawPixel(1, 4, ST7735_BLACK);
		ST7735_DrawPixel(4, 4, ST7735_BLACK);
	}
	if ( SystemFlags.led_counter >= SYSTICK_LEDCNTR_FULL )
	{
		SystemFlags.led_counter = 0;
		ST7735_FillRectangle(1, 1, 4, 4, ST7735_BLACK);
	}
}

static void draw_envelope_led(uint8_t state)
{
	if ( state == 1 )
	{
		ST7735_FillRectangle(1, 61, 4, 4, ST7735_RED);
		ST7735_DrawPixel(1, 61, ST7735_BLACK);
		ST7735_DrawPixel(4, 61, ST7735_BLACK);
		ST7735_DrawPixel(1, 64, ST7735_BLACK);
		ST7735_DrawPixel(4, 64, ST7735_BLACK);
	}
	else
	{
		SystemFlags.led_counter = 0;
		ST7735_FillRectangle(1, 61, 4, 4, ST7735_BLACK);
	}
}

void bB101_Vco_ControlLoop(void)
{
	if (( SystemFlags.control_flags & CONTROL_TICK_FLAG ) == CONTROL_TICK_FLAG)
	{
		if (( SystemFlags.control_flags & CONTROL_SYSTICK_FLAG ) == CONTROL_SYSTICK_FLAG)
			SystemFlags.control_flags &= ~CONTROL_SYSTICK_FLAG;
		SystemFlags.control_flags &= ~CONTROL_TICK_FLAG;
		SystemFlags.systick_counter++;
		if ( SystemFlags.systick_counter > SYSTICK_CNTR_MAX )
		{
			SystemFlags.systick_counter = 0;
			SystemFlags.control_flags |= CONTROL_SYSTICK_FLAG;
			MenusDrawStatus();
			poll_pushbtn();
			draw_led();
		}
	}

	if (( SystemFlags.control_flags & CONTROL_ADC_FLAG ) == CONTROL_ADC_FLAG)
	{
		/*
		if (( SystemFlags.delay_flags & DLY_MIXER_POT_MASK) == 0 )
		{
			SystemFlags.delay_sample_multiplier = (float )DELAY_FEEDBACK_POTCONTROL/4096.0F;
			SystemFlags.delay_feedback_multiplier = 1.0-SystemFlags.delay_sample_multiplier;
		}

		if (( SystemFlags.last_tuner_val != ((TUNER_CONTROL >> 4 ) << 4) ) || (( SystemFlags.oscillator_flags & OSC_FM_PENDING) == OSC_FM_PENDING))
		{
			if (( SystemFlags.control_flags & CONTROL_FM) == CONTROL_FM)
			{
				SystemFlags.tuner_delta_multiplier = ((float )VCO_FM - 2048.0F )/ 2048.0F;
				SystemFlags.oscillator_tuner_constant = (SystemFlags.cv_voltage + SystemFlags.cv_voltage_div_10 * (float )VCO_FM / 2048.0F ) ;
			}
			else
			{
				SystemFlags.tuner_delta_multiplier = ((float )TUNER_CONTROL - 2048.0F )/ 2048.0F;
				SystemFlags.oscillator_tuner_constant = (SystemFlags.cv_voltage + SystemFlags.cv_voltage_div_10 * (float )TUNER_CONTROL / 2048.0F ) ;
			}

			SystemFlags.last_tuner_val = (TUNER_CONTROL >> 4 ) << 4;
			SystemFlags.oscillator_flags |= OSC_TUNE_PENDING;
			SystemFlags.oscillator_flags &= ~OSC_FM_PENDING;

		}

		if (( SystemFlags.control_flags & CONTROL_FM) == CONTROL_FM)
		{
			if ( SystemFlags.last_fm_val != ((VCO_FM >> 4 ) << 4) )
			{
				SystemFlags.oscillator_flags |= OSC_FM_PENDING;
				SystemFlags.last_fm_val = (VCO_FM >> 4 ) << 4;
			}
		}

		if (( SystemFlags.vcf_flags & VCF_ENABLED) == VCF_ENABLED )
		{
			if (( SystemFlags.vcf_flags & VCF_CONTROL_MASK ) == VCF_CONTROL_POT)
			{
				VCFParameters.filterCutoff  	= (float )VCF_CUTOFF_POTCONTROL    / 4096.0F;
				VCFParameters.filterResonance = (float )VCF_RESONANCE_POTCONTROL / 4096.0F;
				if (( SystemFlags.effect_flags & EFFECT_MOOG1) == EFFECT_MOOG1)
				{
					Set_Filter1_Coefficients();
				}
				if (( SystemFlags.effect_flags & EFFECT_MOOG2) == EFFECT_MOOG2)
				{
					Set_Filter2_Coefficients();
				}
			}
		}

		if (( SystemFlags.oscillator_flags & OSC_SRCFLAG ) != OSC_SRCFLAG)
		{
	        float voltage = (float )VCO_CV / 409.6F;
	        float vpow = powf(2.0F , voltage);
	        SystemFlags.cv_voltage = (110.0F / 6.727171F * vpow);
	        SystemFlags.cv_voltage_div_10 = SystemFlags.cv_voltage/10.0F;
		}
*/
		/*
		if ( SystemFlags.last_tuner_val != ((LFO_FREQUENCY_POTCONTROL >> 4 ) << 4))
		{
			SystemFlags.tuner_delta_multiplier = ((float )LFO_FREQUENCY_POTCONTROL - 2048.0F )/ 2048.0F;
			SystemFlags.oscillator_tuner_constant = (SystemFlags.cv_voltage + SystemFlags.cv_voltage_div_10 * (float )LFO_FREQUENCY_POTCONTROL / 2048.0F ) ;
			SystemFlags.last_tuner_val = (LFO_FREQUENCY_POTCONTROL >> 4 ) << 4;
		}
*/
		if ( SystemFlags.last_env_timing_val != ((ENV_TIMING_POTCONTROL >> 4 ) << 4) )
		{
			SystemFlags.last_env_timing_val = (ENV_TIMING_POTCONTROL >> 4 ) << 4;
			SystemFlags.env_timing = 0xffff - ( ENV_TIMING_POTCONTROL << 4 );
			if ( SystemFlags.env_timing < 1000 )
				SystemFlags.env_timing = 1000;
		}

		SystemFlags.control_flags &= ~CONTROL_ADC_FLAG;
	}
	if (( SystemFlags.control_flags & CONTROL_ENVELOPE_FLAG ) == CONTROL_ENVELOPE_FLAG)
	{
		SystemFlags.control_flags &= ~CONTROL_ENVELOPE_FLAG;

		HAL_TIM_Base_Stop_IT(&ENVELOPE_TIMER);
		ENVELOPE_TIMER.Instance->ARR = SystemFlags.env_timing;


		if (( SystemFlags.control_flags & CONTROL_ENVELOPE_LED ) == CONTROL_ENVELOPE_LED)
		{
			SystemFlags.control_flags &= ~CONTROL_ENVELOPE_LED;
			draw_envelope_led(0);
		}
		else
		{
			SystemFlags.control_flags |= CONTROL_ENVELOPE_LED;
			draw_envelope_led(1);
		}
		HAL_TIM_Base_Start_IT(&ENVELOPE_TIMER);

	}
}

