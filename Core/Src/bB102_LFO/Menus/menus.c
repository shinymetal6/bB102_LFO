/*
 * menus.c
 *
 *  Created on: Jul 16, 2021
 *      Author: fil
 */


#include "main.h"
uint16_t	line_ptr = 0;
__attribute__((section(".table"))) static const ScreenTypeDef	Main_Menu_Screen[] = {
		{
				"bB102",
				MENU_X_TITLE,
				MENU_Y_TITLE,
				ST7735_BLUE,
				ST7735_BLACK
		},
		{
				"LFOs",
				LINE1_X,
				LINE1_Y,
				ST7735_BLUE,
				ST7735_BLACK
		},
		{
				"Env",
				LINE2_X,
				LINE2_Y,
				ST7735_BLUE,
				ST7735_BLACK
		},
		{
				"System",
				LINE3_X,
				LINE3_Y,
				ST7735_BLUE,
				ST7735_BLACK
		},
		{
				" ",
		},
};

__attribute__((section(".table"))) static const ScreenTypeDef	Osc_Menu_Screen[] = {
		{
				"LFOs",
				MENU_X_TITLE,
				MENU_Y_TITLE,
				ST7735_BLUE,
				ST7735_BLACK
		},
		{
				"Wave",
				LINE1_X,
				LINE1_Y,
				ST7735_BLUE,
				ST7735_BLACK
		},
		{
				"Duty",
				LINE2_X,
				LINE2_Y,
				ST7735_BLUE,
				ST7735_BLACK
		},
		{
				"deTune",
				LINE3_X,
				LINE3_Y,
				ST7735_BLUE,
				ST7735_BLACK
		},
		{
				"Volume",
				LINE4_X,
				LINE4_Y,
				ST7735_BLUE,
				ST7735_BLACK
		},
		{
				"Return",
				LINE5_X,
				LINE5_Y,
				ST7735_BLUE,
				ST7735_BLACK
		},
		{
				" ",
		},
};
__attribute__((section(".table"))) static const ScreenTypeDef	Osc_WaveMenu_Screen[] = {
		{
				"Waves",
				MENU_X_TITLE,
				MENU_Y_TITLE,
				ST7735_BLUE,
				ST7735_BLACK
		},
		{
				"Wave 1",
				LINE1_X,
				LINE1_Y,
				ST7735_BLUE,
				ST7735_BLACK
		},
		{
				"Wave 2",
				LINE2_X,
				LINE2_Y,
				ST7735_BLUE,
				ST7735_BLACK
		},
		{
				"Wave 3",
				LINE3_X,
				LINE3_Y,
				ST7735_BLUE,
				ST7735_BLACK
		},
		{
				"Wave 4",
				LINE4_X,
				LINE4_Y,
				ST7735_BLUE,
				ST7735_BLACK
		},
		{
				"Return",
				LINE5_X,
				LINE5_Y,
				ST7735_BLUE,
				ST7735_BLACK
		},
		{
				" ",
		},
};
__attribute__((section(".table"))) static const ScreenTypeDef	Osc_DutyMenu_Screen[] = {
		{
				"Duty",
				MENU_X_TITLE,
				MENU_Y_TITLE,
				ST7735_BLUE,
				ST7735_BLACK
		},
		{
				"Duty 1",
				LINE1_X,
				LINE1_Y,
				ST7735_BLUE,
				ST7735_BLACK
		},
		{
				"Duty 2",
				LINE2_X,
				LINE2_Y,
				ST7735_BLUE,
				ST7735_BLACK
		},
		{
				"Duty 3",
				LINE3_X,
				LINE3_Y,
				ST7735_BLUE,
				ST7735_BLACK
		},
		{
				"Duty 4",
				LINE4_X,
				LINE4_Y,
				ST7735_BLUE,
				ST7735_BLACK
		},
		{
				"Return",
				LINE5_X,
				LINE5_Y,
				ST7735_BLUE,
				ST7735_BLACK
		},
		{
				" ",
		},
};

__attribute__((section(".table"))) static const ScreenTypeDef	Osc_DeTuneMenu_Screen[] = {
		{
				"dTune",
				MENU_X_TITLE,
				MENU_Y_TITLE,
				ST7735_BLUE,
				ST7735_BLACK
		},
		{
				"deTune 1",
				LINE1_X,
				LINE1_Y,
				ST7735_BLUE,
				ST7735_BLACK
		},
		{
				"deTune 2",
				LINE2_X,
				LINE2_Y,
				ST7735_BLUE,
				ST7735_BLACK
		},
		{
				"deTune 3",
				LINE3_X,
				LINE3_Y,
				ST7735_BLUE,
				ST7735_BLACK
		},
		{
				"deTune 4",
				LINE4_X,
				LINE4_Y,
				ST7735_BLUE,
				ST7735_BLACK
		},
		{
				"Return",
				LINE5_X,
				LINE5_Y,
				ST7735_BLUE,
				ST7735_BLACK
		},
		{
				" ",
		},
};

__attribute__((section(".table"))) static const ScreenTypeDef	Osc_VolumeMenu_Screen[] = {
		{
				"Vol",
				MENU_X_TITLE,
				MENU_Y_TITLE,
				ST7735_BLUE,
				ST7735_BLACK
		},
		{
				"Volume 1",
				LINE1_X,
				LINE1_Y,
				ST7735_BLUE,
				ST7735_BLACK
		},
		{
				"Volume 2",
				LINE2_X,
				LINE2_Y,
				ST7735_BLUE,
				ST7735_BLACK
		},
		{
				"Volume 3",
				LINE3_X,
				LINE3_Y,
				ST7735_BLUE,
				ST7735_BLACK
		},
		{
				"Volume 4",
				LINE4_X,
				LINE4_Y,
				ST7735_BLUE,
				ST7735_BLACK
		},
		{
				"Return",
				LINE5_X,
				LINE5_Y,
				ST7735_BLUE,
				ST7735_BLACK
		},
		{
				" ",
		},
};


__attribute__((section(".table"))) static const ScreenTypeDef	System_Menu_Screen[] = {
		{
				"Sys",
				MENU_X_TITLE,
				MENU_Y_TITLE,
				ST7735_BLUE,
				ST7735_BLACK
		},
		{
				"Input",
				LINE1_X,
				LINE1_Y,
				ST7735_BLUE,
				ST7735_BLACK
		},
		{
				"VCA",
				LINE2_X,
				LINE2_Y,
				ST7735_BLUE,
				ST7735_BLACK
		},
		{
				"FM",
				LINE3_X,
				LINE3_Y,
				ST7735_BLUE,
				ST7735_BLACK
		},
		{
				"Seq",
				LINE4_X,
				LINE4_Y,
				ST7735_BLUE,
				ST7735_BLACK
		},
		{
				"Memory",
				LINE5_X,
				LINE5_Y,
				ST7735_BLUE,
				ST7735_BLACK
		},
		{
				"Return",
				LINE6_X,
				LINE6_Y,
				ST7735_BLUE,
				ST7735_BLACK
		},
		{
				" ",
		},
};

__attribute__((section(".table"))) static const ScreenTypeDef	System_PGM_Menu_Screen[] = {
		{
				"Mem",
				MENU_X_TITLE,
				MENU_Y_TITLE,
				ST7735_BLUE,
				ST7735_BLACK
		},
		{
				"PGM num",
				LINE1_X,
				LINE1_Y,
				ST7735_BLUE,
				ST7735_BLACK
		},
		{
				"LOAD",
				LINE3_X,
				LINE3_Y,
				ST7735_BLUE,
				ST7735_BLACK
		},
		{
				"STORE",
				LINE4_X,
				LINE4_Y,
				ST7735_BLUE,
				ST7735_BLACK
		},
		{
				"Return",
				LINE5_X,
				LINE5_Y,
				ST7735_BLUE,
				ST7735_BLACK
		},
		{
				" ",
		},
};

void Menus_Hilight_Line(ScreenTypeDef *screen, uint16_t old_line_number, uint16_t new_line_number)
{
	ST7735_WriteString(screen[old_line_number].x,screen[old_line_number].y,screen[old_line_number].line, Font_7x10, screen[old_line_number].fcolor, screen[old_line_number].bcolor);
	ST7735_WriteString(screen[new_line_number].x,screen[new_line_number].y,screen[new_line_number].line, Font_7x10, ST7735_BLACK, ST7735_BLACK);
	ST7735_WriteString(screen[new_line_number].x,screen[new_line_number].y,screen[new_line_number].line, Font_7x10, screen[new_line_number].bcolor, screen[new_line_number].fcolor);
}

void Draw_Menu(ScreenTypeDef *screen)
{
uint8_t	i=0;
	while(screen[i].line[0] != 0x20 )
	{
		if (( screen == Main_Menu_Screen ) && (i == 0 ))
		{
			ST7735_WriteString(screen[i].x,   screen[i].y,SystemParameters.Header,  Font_7x10, ST7735_BLUE, ST7735_BLACK);
			ST7735_WriteString(screen[i].x+(strlen(SystemParameters.Header)*7)+4,screen[i].y,SystemParameters.Version, Font_7x10, ST7735_BLUE, ST7735_BLACK);
		}
		if ( i == 1 )
		{
			SystemFlags.menu_line_counter = 1;
			ST7735_WriteString(screen[i].x,screen[i].y,screen[i].line, Font_7x10, ST7735_BLACK, ST7735_BLUE);
		}
		else
			ST7735_WriteString(screen[i].x,screen[i].y,screen[i].line, Font_7x10, ST7735_BLUE, ST7735_BLACK);
		i++;
	}
}

void Main_Menu(void)
{
	ST7735_FillScreen(ST7735_BLACK);
	Draw_Menu((ScreenTypeDef *)&Main_Menu_Screen);
}

void Osc_Menu(void)
{
	ST7735_FillScreen(ST7735_BLACK);
	Draw_Menu((ScreenTypeDef *)&Osc_Menu_Screen);
}

void Osc_WaveMenu(void)
{
	ST7735_FillScreen(ST7735_BLACK);
	Draw_Menu((ScreenTypeDef *)&Osc_WaveMenu_Screen);
}

void move_menu(ScreenTypeDef *screen, uint16_t old_line_number, uint16_t new_line_number, uint16_t max_line_number)
{
	if (( SystemFlags.buttons_flag & BUTTON_TACT0) == BUTTON_TACT0)
	{
		if ( SystemFlags.menu_line_counter == 1 )
			SystemFlags.menu_line_counter = max_line_number;
		else
			SystemFlags.menu_line_counter --;
		SystemFlags.buttons_flag &= ~BUTTON_TACT0;
	}
	if (( SystemFlags.buttons_flag & BUTTON_TACT1) == BUTTON_TACT1)
	{
		if ( SystemFlags.menu_line_counter >= max_line_number )
			SystemFlags.menu_line_counter = 1;
		else
			SystemFlags.menu_line_counter ++;
		SystemFlags.buttons_flag &= ~BUTTON_TACT1;
	}
	Menus_Hilight_Line(screen,old_line_number,SystemFlags.menu_line_counter);
}

void change_menu(ScreenTypeDef *new_screen,ScreenTypeDef *old_screen)
{
#ifdef	SLOW_FILL
	ST7735_FillScreen(ST7735_BLACK);
#else
uint8_t	i=0;
	SystemFlags.menu_line_counter = 1;
	while(old_screen[i].line[0] != 0x20 )
	{
		ST7735_WriteString(old_screen[i].x,old_screen[i].y,old_screen[i].line, Font_7x10, ST7735_BLACK, ST7735_BLACK);
		i++;
	}
#endif
	Draw_Menu(new_screen);
}

void Draw_Waveform(uint8_t oscillator_offset,uint8_t waveform)
{
	switch (waveform)
	{
	case	SQUARE		:	ST7735_DrawImage(LINE_X_LFO1W+oscillator_offset*16,LINE_Y_LFOW+1, 14, 14, sqrw); break;
	case	TRIANGLE	:	ST7735_DrawImage(LINE_X_LFO1W+oscillator_offset*16,LINE_Y_LFOW+1, 14, 14, tria); break;
	default				:	ST7735_DrawImage(LINE_X_LFO1W+oscillator_offset*16,LINE_Y_LFOW+1, 14, 14, sine); break; // 's' case
	}
}

uint8_t change_oscillator_waveform(uint8_t oscillator_offset )
{
uint8_t	i;

	SystemFlags.lfo_waves[oscillator_offset]++;
	if ( SystemFlags.lfo_waves[oscillator_offset] > SQUARE)
		SystemFlags.lfo_waves[oscillator_offset] = SINE;

	for(i=0;i<NUMLFOS;i+=VOICES)
	{
		Lfo[i+oscillator_offset].waveform = SystemFlags.lfo_waves[oscillator_offset];
	}
	Draw_Waveform(oscillator_offset , SystemFlags.lfo_waves[oscillator_offset] );
	return Lfo[oscillator_offset].waveform;
}

void DisplayDuty(void)
{
uint8_t	i,k;
char 	tmp_buf[16];
	k = LINE_X_DUTY;
	for(i=0;i<4;i++)
	{
		sprintf(tmp_buf,"%d",SystemFlags.lfo_duty_percent[i]);
		ST7735_WriteString(k,LINE_Y_DUTY,"  ", Font_7x10, ST7735_DARKGREEN, ST7735_BLACK);
		ST7735_WriteString(k,LINE_Y_DUTY,tmp_buf, Font_7x10, ST7735_DARKGREEN, ST7735_BLACK);
		k += LINE_X_DUTY_DELTA;
	}
}

void DisplayDetune(void)
{
uint8_t	i,k;
char 	tmp_buf[16];
	k = LINE_X_DETUNE;
	for(i=0;i<4;i++)
	{
		sprintf(tmp_buf,"%d",SystemFlags.lfo_detune[i]);
		ST7735_WriteString(k,LINE_Y_DETUNE,"  ", Font_7x10, ST7735_DARKGREEN, ST7735_BLACK);
		ST7735_WriteString(k,LINE_Y_DETUNE,tmp_buf, Font_7x10, ST7735_DARKGREEN, ST7735_BLACK);
		k += LINE_X_DETUNE_DELTA;
	}
}

void DisplayVolume(void)
{
uint8_t	i,k;
char 	tmp_buf[16];
	k = LINE_X_VOLUME;
	for(i=0;i<4;i++)
	{
		sprintf(tmp_buf,"%d",SystemFlags.lfo_volume[i]);
		ST7735_WriteString(k,LINE_Y_VOLUME,"  ", Font_7x10, ST7735_DARKGREEN, ST7735_BLACK);
		ST7735_WriteString(k,LINE_Y_VOLUME,tmp_buf, Font_7x10, ST7735_DARKGREEN, ST7735_BLACK);
		k += LINE_X_DETUNE_DELTA;
	}
}

uint8_t ChangeLfoVolume(uint8_t oscillator_offset )
{
uint8_t	i;

	if ( SystemFlags.lfo_volume[oscillator_offset] > 10 )
		SystemFlags.lfo_volume[oscillator_offset] = 10;

	for(i=0;i<NUMLFOS;i+=VOICES)
	{
		Lfo[i+oscillator_offset].volume = (float )SystemFlags.lfo_volume[oscillator_offset] / 10.0F;
	}
	return 0;
}

uint8_t ChangeLfoDuty(uint8_t oscillator_offset )
{
uint8_t	i;

	if ( SystemFlags.lfo_duty_percent[oscillator_offset] > 99 )
		SystemFlags.lfo_duty_percent[oscillator_offset] = 99;

	for(i=0;i<NUMLFOS;i+=VOICES)
	{
		Lfo[i+oscillator_offset].duty += (uint8_t )((float )SystemFlags.lfo_duty_percent[oscillator_offset] * 2.55F );
		ChangeLfoWavePhase(i+oscillator_offset,Lfo[i+oscillator_offset].waveform , Lfo[i+oscillator_offset].duty );
	}
	return 0;
}

uint8_t ChangeLfoDetune(uint8_t oscillator_offset )
{
uint8_t	i;
	for(i=0;i<NUMLFOS;i+=VOICES)
	{
		if ( SystemFlags.lfo_detune[oscillator_offset] < 50 )
		{
			Lfo[i+oscillator_offset].detune = (50.0F - (float )SystemFlags.lfo_detune[oscillator_offset]) / 10.0F;
		}
		else
		{
			Lfo[i+oscillator_offset].detune = ((float )SystemFlags.lfo_detune[oscillator_offset] - 50.0F) / 10.0F;
		}
		SetDetune(i+oscillator_offset);
	}
	return 0;
}

void view_sequence(void)
{
}

void view_delay(void)
{
}

void view_delay_val(void)
{
}

void view_am(void)
{
uint16_t	color;

	if (( SystemFlags.control_flags & CONTROL_VCA) == CONTROL_VCA)
		color = ST7735_DARKGREEN;
	else
		color = ST7735_GREY;
	ST7735_WriteString(LINE_X_INPUT+14,LINE_Y_INPUT,"a", Font_7x10, color, ST7735_BLACK);
}

void draw_filter_params(void)
{
}

void draw_effect(void)
{
}

void DoMenus(void)
{
uint16_t	old_line_number;
ScreenTypeDef	*current_screen;

	switch ( SystemFlags.menu_state)
	{
	case	MENU_STATE_TOP:
		current_screen = (ScreenTypeDef *)&Main_Menu_Screen;
		if ((( SystemFlags.buttons_flag & BUTTON_TACT0) == BUTTON_TACT0) || (( SystemFlags.buttons_flag & BUTTON_TACT1) == BUTTON_TACT1))
		{
			old_line_number = SystemFlags.menu_line_counter;
			move_menu(current_screen,old_line_number,SystemFlags.menu_line_counter,MENU_MAX_TOP_LINE);
		}
		if (( SystemFlags.buttons_flag & BUTTON_TACT2) == BUTTON_TACT2)
		{
			if ( SystemFlags.menu_line_counter == 1)
			{
				SystemFlags.menu_state = MENU_STATE_LFO_TOP;
				change_menu((ScreenTypeDef *)&Osc_Menu_Screen,current_screen);
			}

			if ( SystemFlags.menu_line_counter == MENU_MAX_TOP_LINE)
			{
				SystemFlags.menu_state = MENU_STATE_SYSTEM;
				change_menu((ScreenTypeDef *)&System_Menu_Screen,current_screen);
			}
		}
		break;
	case	MENU_STATE_LFO_TOP:
		current_screen = (ScreenTypeDef *)&Osc_Menu_Screen;
		if ((( SystemFlags.buttons_flag & BUTTON_TACT0) == BUTTON_TACT0) || (( SystemFlags.buttons_flag & BUTTON_TACT1) == BUTTON_TACT1))
		{
			old_line_number = SystemFlags.menu_line_counter;
			move_menu(current_screen,old_line_number,SystemFlags.menu_line_counter,MENU_MAX_LFO_LINE);
		}
		if (( SystemFlags.buttons_flag & BUTTON_TACT2) == BUTTON_TACT2)
		{
			if ( SystemFlags.menu_line_counter == MENU_MAX_LFO_LINE)
			{
				SystemFlags.menu_state = MENU_STATE_TOP;
				change_menu((ScreenTypeDef *)&Main_Menu_Screen,current_screen);
			}
			else
			{
				if ( SystemFlags.menu_line_counter == 1)
				{
					SystemFlags.menu_state = MENU_STATE_LFO_WAVE;
					change_menu((ScreenTypeDef *)&Osc_WaveMenu_Screen,current_screen);
				}
				if ( SystemFlags.menu_line_counter == 2)
				{
					SystemFlags.menu_state = MENU_STATE_LFO_DUTY;
					change_menu((ScreenTypeDef *)&Osc_DutyMenu_Screen,current_screen);
					DisplayDuty();
				}
				if ( SystemFlags.menu_line_counter == 3)
				{
					SystemFlags.menu_state = MENU_STATE_LFO_DETUNE;
					change_menu((ScreenTypeDef *)&Osc_DeTuneMenu_Screen,current_screen);
					DisplayDetune();
				}
				if ( SystemFlags.menu_line_counter == 4)
				{
					SystemFlags.menu_state = MENU_STATE_LFO_VOLUME;
					change_menu((ScreenTypeDef *)&Osc_VolumeMenu_Screen,current_screen);
					DisplayVolume();
				}
			}
		}
		break;
	case	MENU_STATE_LFO_WAVE:
		current_screen = (ScreenTypeDef *)&Osc_WaveMenu_Screen;
		if ((( SystemFlags.buttons_flag & BUTTON_TACT0) == BUTTON_TACT0) || (( SystemFlags.buttons_flag & BUTTON_TACT1) == BUTTON_TACT1))
		{
			old_line_number = SystemFlags.menu_line_counter;
			move_menu(current_screen,old_line_number,SystemFlags.menu_line_counter,MENU_MAX_LFO_WAVE_LINE);
			SystemFlags.buttons_flag &= ~( BUTTON_TACT0 | BUTTON_TACT1);
		}
		if (( SystemFlags.buttons_flag & BUTTON_TACT2) == BUTTON_TACT2)
		{
			if ( SystemFlags.menu_line_counter == MENU_MAX_LFO_WAVE_LINE)
			{
				SystemFlags.menu_state = MENU_STATE_LFO_TOP;
				change_menu((ScreenTypeDef *)&Osc_Menu_Screen,current_screen);
			}
			else
				change_oscillator_waveform(SystemFlags.menu_line_counter-1);
		}
		break;
	case	MENU_STATE_LFO_DUTY:
		current_screen = (ScreenTypeDef *)&Osc_DutyMenu_Screen;
		if ((( SystemFlags.buttons_flag & BUTTON_TACT0) == BUTTON_TACT0) || (( SystemFlags.buttons_flag & BUTTON_TACT1) == BUTTON_TACT1))
		{
			old_line_number = SystemFlags.menu_line_counter;
			move_menu(current_screen,old_line_number,SystemFlags.menu_line_counter,MENU_MAX_LFO_DUTY_LINE);
			SystemFlags.buttons_flag &= ~( BUTTON_TACT0 | BUTTON_TACT1);
		}
		if (( SystemFlags.buttons_flag & BUTTON_TACT2) == BUTTON_TACT2)
		{
			if ( SystemFlags.menu_line_counter == MENU_MAX_LFO_DUTY_LINE)
			{
				SystemFlags.menu_state = MENU_STATE_LFO_TOP;
				change_menu((ScreenTypeDef *)&Osc_Menu_Screen,current_screen);
			}
			else
			{
				if ( SystemFlags.lfo_duty_percent[SystemFlags.menu_line_counter-1] < 95 )
					SystemFlags.lfo_duty_percent[SystemFlags.menu_line_counter-1] += 5;
				else
					SystemFlags.lfo_duty_percent[SystemFlags.menu_line_counter-1] = 5;

				ChangeLfoDuty(SystemFlags.menu_line_counter-1);
				DisplayDuty();
			}
		}
		break;
	case	MENU_STATE_LFO_DETUNE:
		current_screen = (ScreenTypeDef *)&Osc_DeTuneMenu_Screen;
		if ((( SystemFlags.buttons_flag & BUTTON_TACT0) == BUTTON_TACT0) || (( SystemFlags.buttons_flag & BUTTON_TACT1) == BUTTON_TACT1))
		{
			old_line_number = SystemFlags.menu_line_counter;
			move_menu(current_screen,old_line_number,SystemFlags.menu_line_counter,MENU_MAX_LFO_DETUNE_LINE);
			SystemFlags.buttons_flag &= ~( BUTTON_TACT0 | BUTTON_TACT1);
		}
		if (( SystemFlags.buttons_flag & BUTTON_TACT2) == BUTTON_TACT2)
		{
			if ( SystemFlags.menu_line_counter == MENU_MAX_LFO_DETUNE_LINE)
			{
				SystemFlags.menu_state = MENU_STATE_LFO_TOP;
				change_menu((ScreenTypeDef *)&Osc_Menu_Screen,current_screen);
			}
			else
			{
				if ( SystemFlags.lfo_detune[SystemFlags.menu_line_counter-1] < 99 )
					SystemFlags.lfo_detune[SystemFlags.menu_line_counter-1] += 1;
				else
					SystemFlags.lfo_detune[SystemFlags.menu_line_counter-1] = 0;
				ChangeLfoDetune(SystemFlags.menu_line_counter-1);
				DisplayDetune();
			}
		}
		break;
	case	MENU_STATE_LFO_VOLUME:
		current_screen = (ScreenTypeDef *)&Osc_VolumeMenu_Screen;
		if ((( SystemFlags.buttons_flag & BUTTON_TACT0) == BUTTON_TACT0) || (( SystemFlags.buttons_flag & BUTTON_TACT1) == BUTTON_TACT1))
		{
			old_line_number = SystemFlags.menu_line_counter;
			move_menu(current_screen,old_line_number,SystemFlags.menu_line_counter,MENU_MAX_LFO_VOLUME_LINE);
			SystemFlags.buttons_flag &= ~( BUTTON_TACT0 | BUTTON_TACT1);
		}
		if (( SystemFlags.buttons_flag & BUTTON_TACT2) == BUTTON_TACT2)
		{
			if ( SystemFlags.menu_line_counter == MENU_MAX_LFO_VOLUME_LINE)
			{
				SystemFlags.menu_state = MENU_STATE_LFO_TOP;
				change_menu((ScreenTypeDef *)&Osc_Menu_Screen,current_screen);
			}
			else
			{
				if ( SystemFlags.lfo_volume[SystemFlags.menu_line_counter-1] < 10 )
					SystemFlags.lfo_volume[SystemFlags.menu_line_counter-1] += 1;
				else
					SystemFlags.lfo_volume[SystemFlags.menu_line_counter-1] = 0;
				ChangeLfoVolume(SystemFlags.menu_line_counter-1);
				DisplayVolume();
			}
		}
		break;
	case	MENU_STATE_SYSTEM:
		current_screen = (ScreenTypeDef *)&System_Menu_Screen;
		if ((( SystemFlags.buttons_flag & BUTTON_TACT0) == BUTTON_TACT0) || (( SystemFlags.buttons_flag & BUTTON_TACT1) == BUTTON_TACT1))
		{
			old_line_number = SystemFlags.menu_line_counter;
			move_menu(current_screen,old_line_number,SystemFlags.menu_line_counter,MENU_MAX_SYSTEM_LINE);
		}
		if (( SystemFlags.buttons_flag & BUTTON_TACT2) == BUTTON_TACT2)
		{
			if ( SystemFlags.menu_line_counter == 1)
			{
				if (( SystemFlags.oscillator_flags & LFO_SRCFLAG) == LFO_SRCFLAG)
				{
					SystemFlags.oscillator_flags &= ~LFO_SRCFLAG;
					ST7735_WriteString(LINE_X_INPUT_MIDI, LINE_Y_INPUT, "CV  ", Font_7x10, ST7735_DARKGREEN, ST7735_BLACK);
				}
				else
				{
					SystemFlags.oscillator_flags |= LFO_SRCFLAG;
					ST7735_WriteString(LINE_X_INPUT_MIDI, LINE_Y_INPUT, "MIDI", Font_7x10, ST7735_DARKGREEN, ST7735_BLACK);
				}
			}
			if ( SystemFlags.menu_line_counter == 2)
			{
				if (( SystemFlags.control_flags & CONTROL_VCA) == CONTROL_VCA)
					SystemFlags.control_flags &= ~CONTROL_VCA;
				else
					SystemFlags.control_flags |= CONTROL_VCA;
				view_am();
			}
			if ( SystemFlags.menu_line_counter == 3)
			{
			}

			if ( SystemFlags.menu_line_counter == 4)
			{
			}
			if ( SystemFlags.menu_line_counter == 5)
			{
				SystemFlags.menu_state = MENU_STATE_PGM;
				SystemFlags.program_number = 0;
				change_menu((ScreenTypeDef *)&System_PGM_Menu_Screen,current_screen);
				char tmp_buf[4];
				sprintf(tmp_buf,"%d",SystemFlags.program_number);
				ST7735_WriteString(LINE2_X+4, LINE2_Y, tmp_buf, Font_7x10, ST7735_DARKGREEN, ST7735_BLACK);
			}
			if ( SystemFlags.menu_line_counter == MENU_MAX_SYSTEM_LINE)
			{
				SystemFlags.menu_state = MENU_STATE_TOP;
				change_menu((ScreenTypeDef *)&Main_Menu_Screen,current_screen);
			}
		}
		break;
	case	MENU_STATE_PGM:
		current_screen = (ScreenTypeDef *)&System_PGM_Menu_Screen;
		if ((( SystemFlags.buttons_flag & BUTTON_TACT0) == BUTTON_TACT0) || (( SystemFlags.buttons_flag & BUTTON_TACT1) == BUTTON_TACT1))
		{
			old_line_number = SystemFlags.menu_line_counter;
			move_menu(current_screen,old_line_number,SystemFlags.menu_line_counter,MENU_MAX_PGM_LINE);
		}
		if (( SystemFlags.buttons_flag & BUTTON_TACT2) == BUTTON_TACT2)
		{
			if ( SystemFlags.menu_line_counter == 1)
			{
				SystemFlags.program_number++;
				SystemFlags.program_number &= (NUM_PROGRAMS_MAX-1);
				char tmp_buf[4];
				sprintf(tmp_buf,"%d",SystemFlags.program_number);
				ST7735_WriteString(LINE2_X+4, LINE2_Y, tmp_buf, Font_7x10, ST7735_DARKGREEN, ST7735_BLACK);
			}
			if ( SystemFlags.menu_line_counter == 2)
			{
				if ( ee24_load_program(SystemFlags.program_number) != 0)
					ST7735_WriteString(LINE2_X, LINE2_Y, "FAIL", Font_7x10, ST7735_RED, ST7735_BLACK);
				else
				{
					SystemFlags.menu_state = MENU_STATE_SYSTEM;
					MenusDrawStatus();
					Draw_Waveform(0 , SystemFlags.lfo_waves[0] );
					Draw_Waveform(1 , SystemFlags.lfo_waves[1] );
					Draw_Waveform(2 , SystemFlags.lfo_waves[2] );
					Draw_Waveform(3 , SystemFlags.lfo_waves[3] );
					view_sequence();
					SystemFlags.menu_state = MENU_STATE_TOP;
					change_menu((ScreenTypeDef *)&Main_Menu_Screen,current_screen);
				}
			}
			if ( SystemFlags.menu_line_counter == 3)
			{
				ee24_store_program(SystemFlags.program_number);
				SystemFlags.menu_state = MENU_STATE_TOP;
				change_menu((ScreenTypeDef *)&Main_Menu_Screen,current_screen);
			}

			if ( SystemFlags.menu_line_counter == MENU_MAX_PGM_LINE)
			{
				SystemFlags.menu_state = MENU_STATE_SYSTEM;
				change_menu((ScreenTypeDef *)&System_Menu_Screen,current_screen);
			}
		}
		break;
		/*
	case	MENU_STATE_STOREPGM:
		current_screen = (ScreenTypeDef *)&System_StorePGM_Menu_Screen;
		if ((( SystemFlags.buttons_flag & BUTTON_TACT0) == BUTTON_TACT0) || (( SystemFlags.buttons_flag & BUTTON_TACT1) == BUTTON_TACT1))
		{
			old_line_number = SystemFlags.menu_line_counter;
			move_menu(current_screen,old_line_number,SystemFlags.menu_line_counter,MENU_MAX_STOREPGM_LINE);
		}
		if (( SystemFlags.buttons_flag & BUTTON_TACT2) == BUTTON_TACT2)
		{
			if ( SystemFlags.menu_line_counter == 1)
			{
				SystemFlags.program_number++;
				SystemFlags.program_number &= (NUM_PROGRAMS_MAX-1);
				char tmp_buf[4];
				sprintf(tmp_buf,"%d",SystemFlags.program_number);
				ST7735_WriteString(LINE2_X+4, LINE2_Y, tmp_buf, Font_7x10, ST7735_DARKGREEN, ST7735_BLACK);
			}
			if ( SystemFlags.menu_line_counter == 2)
			{
				ee24_store_program(SystemFlags.program_number);
				SystemFlags.menu_state = MENU_STATE_SYSTEM;
				change_menu((ScreenTypeDef *)&System_Menu_Screen,current_screen);
			}
			if ( SystemFlags.menu_line_counter == MENU_MAX_STOREPGM_LINE)
			{
				SystemFlags.menu_state = MENU_STATE_SYSTEM;
				change_menu((ScreenTypeDef *)&System_Menu_Screen,current_screen);
			}
		}
		break;
		*/
	}
	SystemFlags.buttons_flag &= ~(BUTTON_TACT0 | BUTTON_TACT1 | BUTTON_TACT2);

}

void bB101_Print_Tuner(void)
{
	/*
char 	tmp_buf[5];
int		value;
	value = (int ) ((TUNER_CONTROL  - 2048 )/ 20);
	if ( value > 98 )
		value = 98;
	if ( value < -98 )
		value = -98;
	sprintf(tmp_buf,"%d%% ",value);
	ST7735_WriteString(LINE_X_TUNER, LINE_Y_TUNER, tmp_buf, Font_7x10, ST7735_DARKGREEN, ST7735_BLACK);
	*/
}

void MenusDrawEmptyStatus(void)
{
uint8_t	i;

	for(i=0;i<4;i++)
		Draw_Waveform(i,SystemFlags.lfo_waves[i]);
	ST7735_WriteString(LINE_X_FILTER,LINE_Y_FILTER,"LP", Font_7x10, ST7735_DARKGREEN, ST7735_BLACK);
	if (( SystemFlags.oscillator_flags & LFO_SRCFLAG) == LFO_SRCFLAG)
	{
		ST7735_WriteString(LINE_X_INPUT_MIDI, LINE_Y_INPUT, "MIDI", Font_7x10, ST7735_DARKGREEN, ST7735_BLACK);
	}

	view_sequence();
	view_delay();
	view_delay_val();
	draw_filter_params();
	draw_effect();
	view_am();
}

void MenusDrawStatus(void)
{
	bB101_Print_Tuner();
}

