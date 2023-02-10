/*
 * Author: Sandra Ayman
 * Version: V0.0.0
 * Date: 3-1-2023
 * Description: MTIMER2_Private.h
 */

#ifndef MTIMER2_PRIVATE_H_H_
#define MTIMER2_PRIVATE_H_H_

/*----------BASE ADDRESS----------*/
#define MTIM2_BASE_ADDRESS     0x40000000
#define MTIM3_BASE_ADDRESS     0x40000400
#define MTIM4_BASE_ADDRESS     0x40000800
#define MTIM5_BASE_ADDRESS     0x40000C00

/*----------Timer2 Register Addresses----------*/
#define MTIM2_CR1    *( (( volatile u32* )( MTIM2_BASE_ADDRESS + 0x00 )) )
#define MTIM2_CR2    *( (( volatile u32* )( MTIM2_BASE_ADDRESS + 0x04 )) )
#define MTIM2_SMCR   *( (( volatile u32* )( MTIM2_BASE_ADDRESS + 0x08 )) )
#define MTIM2_DIER   *( (( volatile u32* )( MTIM2_BASE_ADDRESS + 0x0C )) )
#define MTIM2_SR     *( (( volatile u32* )( MTIM2_BASE_ADDRESS + 0x10 )) )
#define MTIM2_EGR    *( (( volatile u32* )( MTIM2_BASE_ADDRESS + 0x14 )) )
#define MTIM2_CCMR1  *( (( volatile u32* )( MTIM2_BASE_ADDRESS + 0x18 )) )
#define MTIM2_CCMR2  *( (( volatile u32* )( MTIM2_BASE_ADDRESS + 0x1C )) )
#define MTIM2_CCER   *( (( volatile u32* )( MTIM2_BASE_ADDRESS + 0x20 )) )
#define MTIM2_CNT    *( (( volatile u32* )( MTIM2_BASE_ADDRESS + 0x24 )) )
#define MTIM2_PSC    *( (( volatile u32* )( MTIM2_BASE_ADDRESS + 0x28 )) )
#define MTIM2_ARR    *( (( volatile u32* )( MTIM2_BASE_ADDRESS + 0x2C )) )
#define MTIM2_CCR1   *( (( volatile u32* )( MTIM2_BASE_ADDRESS + 0x34 )) )
#define MTIM2_CCR2   *( (( volatile u32* )( MTIM2_BASE_ADDRESS + 0x38 )) )
#define MTIM2_CCR3   *( (( volatile u32* )( MTIM2_BASE_ADDRESS + 0x3C )) )
#define MTIM2_CCR4   *( (( volatile u32* )( MTIM2_BASE_ADDRESS + 0x40 )) )
#define MTIM2_DCR    *( (( volatile u32* )( MTIM2_BASE_ADDRESS + 0x48 )) )
#define MTIM2_DMAR   *( (( volatile u32* )( MTIM2_BASE_ADDRESS + 0x4C )) )
#define MTIM2_OR     *( (( volatile u32* )( MTIM2_BASE_ADDRESS + 0x50 )) )

/*----------Timer3 Register Addresses----------*/
#define MTIM3_CR1    *( (( volatile u32* )( MTIM3_BASE_ADDRESS + 0x00 )) )
#define MTIM3_CR2    *( (( volatile u32* )( MTIM3_BASE_ADDRESS + 0x04 )) )
#define MTIM3_SMCR   *( (( volatile u32* )( MTIM3_BASE_ADDRESS + 0x08 )) )
#define MTIM3_DIER   *( (( volatile u32* )( MTIM3_BASE_ADDRESS + 0x0C )) )
#define MTIM3_SR     *( (( volatile u32* )( MTIM3_BASE_ADDRESS + 0x10 )) )
#define MTIM3_EGR    *( (( volatile u32* )( MTIM3_BASE_ADDRESS + 0x14 )) )
#define MTIM3_CCMR1  *( (( volatile u32* )( MTIM3_BASE_ADDRESS + 0x18 )) )
#define MTIM3_CCMR2  *( (( volatile u32* )( MTIM3_BASE_ADDRESS + 0x1C )) )
#define MTIM3_CCER   *( (( volatile u32* )( MTIM3_BASE_ADDRESS + 0x20 )) )
#define MTIM3_CNT    *( (( volatile u32* )( MTIM3_BASE_ADDRESS + 0x24 )) )
#define MTIM3_PSC    *( (( volatile u32* )( MTIM3_BASE_ADDRESS + 0x28 )) )
#define MTIM3_ARR    *( (( volatile u32* )( MTIM3_BASE_ADDRESS + 0x2C )) )
#define MTIM3_CCR1   *( (( volatile u32* )( MTIM3_BASE_ADDRESS + 0x34 )) )
#define MTIM3_CCR2   *( (( volatile u32* )( MTIM3_BASE_ADDRESS + 0x38 )) )
#define MTIM3_CCR3   *( (( volatile u32* )( MTIM3_BASE_ADDRESS + 0x3C )) )
#define MTIM3_CCR4   *( (( volatile u32* )( MTIM3_BASE_ADDRESS + 0x40 )) )
#define MTIM3_DCR    *( (( volatile u32* )( MTIM3_BASE_ADDRESS + 0x48 )) )
#define MTIM3_DMAR   *( (( volatile u32* )( MTIM3_BASE_ADDRESS + 0x4C )) )
#define MTIM3_OR     *( (( volatile u32* )( MTIM3_BASE_ADDRESS + 0x50 )) )

/*----------Timer4 Register Addresses----------*/
#define MTIM4_CR1    *( (( volatile u32* )( MTIM4_BASE_ADDRESS + 0x00 )) )
#define MTIM4_CR2    *( (( volatile u32* )( MTIM4_BASE_ADDRESS + 0x04 )) )
#define MTIM4_SMCR   *( (( volatile u32* )( MTIM4_BASE_ADDRESS + 0x08 )) )
#define MTIM4_DIER   *( (( volatile u32* )( MTIM4_BASE_ADDRESS + 0x0C )) )
#define MTIM4_SR     *( (( volatile u32* )( MTIM4_BASE_ADDRESS + 0x10 )) )
#define MTIM4_EGR    *( (( volatile u32* )( MTIM4_BASE_ADDRESS + 0x14 )) )
#define MTIM4_CCMR1  *( (( volatile u32* )( MTIM4_BASE_ADDRESS + 0x18 )) )
#define MTIM4_CCMR2  *( (( volatile u32* )( MTIM4_BASE_ADDRESS + 0x1C )) )
#define MTIM4_CCER   *( (( volatile u32* )( MTIM4_BASE_ADDRESS + 0x20 )) )
#define MTIM4_CNT    *( (( volatile u32* )( MTIM4_BASE_ADDRESS + 0x24 )) )
#define MTIM4_PSC    *( (( volatile u32* )( MTIM4_BASE_ADDRESS + 0x28 )) )
#define MTIM4_ARR    *( (( volatile u32* )( MTIM4_BASE_ADDRESS + 0x2C )) )
#define MTIM4_CCR1   *( (( volatile u32* )( MTIM4_BASE_ADDRESS + 0x34 )) )
#define MTIM4_CCR2   *( (( volatile u32* )( MTIM4_BASE_ADDRESS + 0x38 )) )
#define MTIM4_CCR3   *( (( volatile u32* )( MTIM4_BASE_ADDRESS + 0x3C )) )
#define MTIM4_CCR4   *( (( volatile u32* )( MTIM4_BASE_ADDRESS + 0x40 )) )
#define MTIM4_DCR    *( (( volatile u32* )( MTIM4_BASE_ADDRESS + 0x48 )) )
#define MTIM4_DMAR   *( (( volatile u32* )( MTIM4_BASE_ADDRESS + 0x4C )) )
#define MTIM4_OR     *( (( volatile u32* )( MTIM4_BASE_ADDRESS + 0x50 )) )

/*----------Timer5 Register Addresses----------*/
#define MTIM5_CR1    *( (( volatile u32* )( MTIM5_BASE_ADDRESS + 0x00 )) )
#define MTIM5_CR2    *( (( volatile u32* )( MTIM5_BASE_ADDRESS + 0x04 )) )
#define MTIM5_SMCR   *( (( volatile u32* )( MTIM5_BASE_ADDRESS + 0x08 )) )
#define MTIM5_DIER   *( (( volatile u32* )( MTIM5_BASE_ADDRESS + 0x0C )) )
#define MTIM5_SR     *( (( volatile u32* )( MTIM5_BASE_ADDRESS + 0x10 )) )
#define MTIM5_EGR    *( (( volatile u32* )( MTIM5_BASE_ADDRESS + 0x14 )) )
#define MTIM5_CCMR1  *( (( volatile u32* )( MTIM5_BASE_ADDRESS + 0x18 )) )
#define MTIM5_CCMR2  *( (( volatile u32* )( MTIM5_BASE_ADDRESS + 0x1C )) )
#define MTIM5_CCER   *( (( volatile u32* )( MTIM5_BASE_ADDRESS + 0x20 )) )
#define MTIM5_CNT    *( (( volatile u32* )( MTIM5_BASE_ADDRESS + 0x24 )) )
#define MTIM5_PSC    *( (( volatile u32* )( MTIM5_BASE_ADDRESS + 0x28 )) )
#define MTIM5_ARR    *( (( volatile u32* )( MTIM5_BASE_ADDRESS + 0x2C )) )
#define MTIM5_CCR1   *( (( volatile u32* )( MTIM5_BASE_ADDRESS + 0x34 )) )
#define MTIM5_CCR2   *( (( volatile u32* )( MTIM5_BASE_ADDRESS + 0x38 )) )
#define MTIM5_CCR3   *( (( volatile u32* )( MTIM5_BASE_ADDRESS + 0x3C )) )
#define MTIM5_CCR4   *( (( volatile u32* )( MTIM5_BASE_ADDRESS + 0x40 )) )
#define MTIM5_DCR    *( (( volatile u32* )( MTIM5_BASE_ADDRESS + 0x48 )) )
#define MTIM5_DMAR   *( (( volatile u32* )( MTIM5_BASE_ADDRESS + 0x4C )) )
#define MTIM5_OR     *( (( volatile u32* )( MTIM5_BASE_ADDRESS + 0x50 )) )

/*----------MTIM2_CR1 Pins----------*/
#define MTIM_CEN  0U
#define MTIM_DIR  4U
#define MTIM_CMS0 5U
#define MTIM_CMS1 6U
#define MTIM_ARPE 7U

/*----------MTIM2_CR2 Pins----------*/
#define MTIM_MMS0  4U
#define MTIM_MMS1  5U
#define MTIM_MMS2  6U

/*----------MTIM2_DIER Pins----------*/
#define MTIM_UIE 0U
#define MTIM_TIE 6U

/*----------MTIM2_SMCR Pins----------*/
#define MTIM_SMS0   0U
#define MTIM_SMS1   1U
#define MTIM_SMS2   2U
#define MTIM_TS0    4U
#define MTIM_TS1    5U
#define MTIM_TS2    6U
#define MTIM_MSM    7U
#define MTIM_ETF0   8U
#define MTIM_ETF1   9U
#define MTIM_ETF2   10U
#define MTIM_ETF3   11U
#define MTIM_ETPS0  12U
#define MTIM_ETPS1  13U
#define MTIM_ECE    14U
#define MTIM_ETP    15U

/*----------MTIM2_EGR Pins----------*/
#define  MTIM_UG 0U
/*----------MTIM2_CCMR1 Pins----------*/
#define MTIM_CC1S0 0U
#define MTIM_CC1S1 1U
#define MTIM_OC1PE 3U
#define MTIM_OC1M0 4U
#define MTIM_OC1M1 5U
#define MTIM_OC1M2 6U
#define MTIM_CC2S0 8U
#define MTIM_CC2S1 9U
#define MTIM_OC2PE 11U
#define MTIM_OC2M0 12U
#define MTIM_OC2M1 13U
#define MTIM_OC2M2 14U

/*----------MTIM2_CCMR2 Pins----------*/
#define MTIM_CC3S0 0U
#define MTIM_CC3S1 1U
#define MTIM_OC3PE 3U
#define MTIM_OC3M0 4U
#define MTIM_OC3M1 5U
#define MTIM_OC3M2 6U
#define MTIM_CC4S0 8U
#define MTIM_CC4S1 9U
#define MTIM_OC4PE 11U
#define MTIM_OC4M0 12U
#define MTIM_OC4M1 13U
#define MTIM_OC4M2 14U

/*----------MTIM2_CCER Pins----------*/
#define MTIM_CC1E  0U
#define MTIM_CC1P  1U
#define MTIM_CC1NP 3U
#define MTIM_CC2E  4U
#define MTIM_CC2P  5U
#define MTIM_CC2NP 7U
#define MTIM_CC3E  8U
#define MTIM_CC3P  9U
#define MTIM_CC3NP 11U
#define MTIM_CC4E  12U
#define MTIM_CC4P  13U
#define MTIM_CC4NP 15U

#endif /*MTIMER2_PRIVATE_H__H_ */
