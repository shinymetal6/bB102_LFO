/*
 * envelope.h
 *
 *  Created on: Aug 5, 2021
 *      Author: fil
 */

#ifndef INC_BB102_LFO_COMPONENTS_GENERATORS_ENVELOPE_H_
#define INC_BB102_LFO_COMPONENTS_GENERATORS_ENVELOPE_H_

#define	ENVELOPE_MAXLEN	256
#define	HALF_NUMBER_OF_ENVELOPE_SAMPLES			(ENVELOPE_MAXLEN / 2)
extern	uint16_t	envelope_out[ENVELOPE_MAXLEN];
extern	uint16_t	envelope_buffer[ENVELOPE_MAXLEN];

extern	void InitEnvelope(void);
extern	void RunEnvelope(uint16_t start , uint16_t end);

#endif /* INC_BB102_LFO_COMPONENTS_GENERATORS_ENVELOPE_H_ */
