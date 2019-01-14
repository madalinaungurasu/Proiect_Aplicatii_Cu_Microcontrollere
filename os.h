
#ifndef OS_H_
#define OS_H_

#define OS_10ms_RUN_TIMER  (10)
#define OS_50ms_RUN_TIMER  (50)
#define OS_100ms_RUN_TIMER (100)
#define OS_500ms_RUN_TIMER (500)
//#define F_CPU (16000000UL)
#define CTC_MATCH_OVERFLOW ((F_CPU / 1000) / 8) 

extern volatile uint8_t  OS_u8Cnt10ms;
extern volatile uint8_t  OS_u8Cnt50ms;
extern volatile uint16_t OS_u16Cnt100ms;
extern volatile uint16_t OS_u16Cnt500ms;

extern void OS_vTimerInit(void);
extern void OS_vCyclicTask5ms(void);
extern void OS_vCyclicTask10ms(void);
extern void OS_vCyclicTask50ms(void);
extern void OS_vCyclicTask100ms(void);
extern void OS_vCyclicTask500ms(void);
extern void OS_vBackgroundTask(void);
extern void OS_vStartFreeRunTimer(void);

#endif /* OS_H_ */
