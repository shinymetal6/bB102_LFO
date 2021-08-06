/*
 * ee24_driver.h
 *
 *  Created on: Jun 25, 2021
 *      Author: fil
 */

#ifndef INC_BB102_LFO_DRIVERS_EEPROM_EE24_DRIVER_H_
#define INC_BB102_LFO_DRIVERS_EEPROM_EE24_DRIVER_H_

#define		EEPROM_ADDRESS		0xA0
#define		EEPROM_PAGE_SIZE	64
#define		EEPROM_I2C_HANDLE	hi2c1

typedef struct _ProgramTypeDef
{
	uint8_t 	program_flags0;
	uint8_t 	program_flags1;
	uint8_t 	oscillator_flagsh,oscillator_flagsl;
	uint8_t 	control_flagsh,control_flagsl;
	uint8_t		lfo_wavesh,lfo_wavesl;
	uint8_t 	lfo_duty_percent[4];
	uint8_t 	lfo_detune[4];
	uint8_t 	lfo_volume[4];	// range 0..10
}ProgramTypeDef;

extern	ProgramTypeDef	Program;
extern	ProgramTypeDef	CurrentProgram;
#define		PROGRAM_SIZE		EEPROM_PAGE_SIZE
#define		PROGRAM_OFFSET		4
#define		NUM_PROGRAMS_MAX	64

extern	void ee24_write(uint16_t address, uint8_t *data, size_t len, uint32_t timeout);
extern	void ee24_read(uint16_t address, uint8_t *data, size_t len, uint32_t timeout);
extern	void ee24_eraseChip(void);
extern	void ee24_read_program(uint16_t program_number);
extern	uint16_t ee24_load_program(uint16_t program_number);
extern	void ee24_store_program(uint16_t program_number);
extern	void ee24_remove_program(uint16_t program_number);
extern	void ee24_get_current_program(void);

#endif /* INC_BB102_LFO_DRIVERS_EEPROM_EE24_DRIVER_H_ */
