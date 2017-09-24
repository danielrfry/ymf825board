#ifndef FMTONE_H
#define FMTONE_H

#define MAX_FM_OPERATOR		4
#define MAX_ELEMENT_PRM		2
#define MAX_OPERATOR_PRM 	7
#define MAX_SD1_ELE_PRM_SZ (MAX_OPERATOR_PRM*MAX_FM_OPERATOR + 2)

//	ToneData Class
typedef struct {
	
	unsigned char		voiceVolume;				//	0 - 31(0[dB]-Mute, 0.6[dB]step)
	unsigned char		elePrm[MAX_ELEMENT_PRM];	// BO(2), LFO(2) | ALG(3)
	unsigned char		opPrm[MAX_FM_OPERATOR][MAX_OPERATOR_PRM];
} ToneData;

//	public
extern void Tone_init( void );
extern void Tone_chgPcn( unsigned char* number, int maxTone );
#endif
