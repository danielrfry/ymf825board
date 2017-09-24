//	fmtone.c
#include	"fmtype.h"
#include	"fmtone.h"
#include	"fmsd1.h"

#define		AVAILABLE_TONE_NUMBER	16
#define 	TONE_MAX 				2

//	Variable
static ToneData* tdptr[AVAILABLE_TONE_NUMBER];

static const ToneData TPRM[TONE_MAX] = {
	{	// Tone 1
		127, {1,0x85},								//
		{
			{0x00,0x7f,0xf4,0xbb,0x00,0x10,0x40},	// op1
			{0x00,0xaf,0xa0,0x0e,0x03,0x10,0x40},	// op2
			{0x00,0x2f,0xf3,0x9b,0x00,0x20,0x41},	// op3
			{0x00,0xaf,0xa0,0x0e,0x01,0x10,0x40}	// op4
		}
	},
	{	// Tone 2
		127, {1,2},								//
		{
			{0x01,0xF0,0xF0,0x03,0x66,0x10,0x00},	// op1
			{0x01,0xF0,0xF0,0x03,0x66,0x20,0x00},	// op2
			{0x01,0xF0,0xF0,0x03,0x66,0x40,0x00},	// op3
			{0x01,0xF0,0xF0,0x03,0x66,0x80,0x00}	// op4
		}
	}
};

void Tone_init( void )
{
	int i;
	for ( i=0; i<AVAILABLE_TONE_NUMBER; i++ ){
		tdptr[i] = FMNULL;
	}
}
void Tone_chgPcn( unsigned char* number, int maxTone )
{
	int	i,j,k,l;
	unsigned char regImage[MAX_SD1_ELE_PRM_SZ*AVAILABLE_TONE_NUMBER + 1 + 4]; // 485

	//	Check Tone Number
	for ( i=0; i<maxTone; i++ ){
		unsigned char tnum = *(number+i);
		if ( tnum >= TONE_MAX ){ return; }
		tdptr[i] = (ToneData*)&(TPRM[tnum]);
	}

	//	top
	regImage[0] = 0x80 + maxTone;

	for ( i=0; i<maxTone; i++ ){
		ToneData* td = tdptr[i];
		unsigned char* riPtr = &regImage[MAX_SD1_ELE_PRM_SZ*i + 1];
		for ( l=0; l<MAX_ELEMENT_PRM; l++ ){
			riPtr[l] = td->elePrm[l];
		}
		for ( j=0; j<MAX_FM_OPERATOR; j++ ){
			for ( k=0; k<MAX_OPERATOR_PRM; k++ ){
				riPtr[MAX_ELEMENT_PRM + MAX_OPERATOR_PRM*j + k] = td->opPrm[j][k];
			}
		}
	}

	//	end 
	regImage[MAX_SD1_ELE_PRM_SZ*maxTone + 1] = 0x80;
	regImage[MAX_SD1_ELE_PRM_SZ*maxTone + 2] = 0x03;
	regImage[MAX_SD1_ELE_PRM_SZ*maxTone + 3] = 0x81;
	regImage[MAX_SD1_ELE_PRM_SZ*maxTone + 4] = 0x80;

	//	 Soft Reset
//    writeSingle(26,0xa3);
//    writeSingle(26,0x00);
	writeSingle(8,0xf6);
	delayMs(1);
	writeSingle(8,0x00);

	writeBurst( 7, regImage, MAX_SD1_ELE_PRM_SZ*maxTone + 5 );
}