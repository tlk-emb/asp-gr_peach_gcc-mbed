/*
 *  @(#) $Id: core_cfg1_out.h 2728 2015-12-30 01:46:11Z ertl-honda $
 */

/*
 *		cfg1_out.cをリンクするために必要なスタブの定義
 */

void sta_ker(void){}
STK_T *const	_kernel_istkpt;

/*
 * .vectorセクションに何かファイルを置かないとエラーとなるため
 */
__attribute__ ((section(".vector")))
void dummy_vector(void){}

/*
 *  リンク時のワーニングを回避するため
 */
int rw_dummy = 1;
int zi_dummy = 0;

/*
 * スキャターではウィークディファニッションが使えないため
 * start.sから参照するシンボルを定義
 */ 
void hardware_init_hook(void){}
void software_init_hook(void){}

/* 
 *  オフセットファイルを生成するための定義 
 */ 
const uint8_t   MAGIC_1 = 0x12; 
const uint16_t  MAGIC_2 = 0x1234; 
const uint32_t  MAGIC_4 = 0x12345678;

const TCB	TCB_enatex = {
	{ NULL, NULL },			/* task_queue */
	NULL,					/* p_tinib */
	0U,						/* tstat */
#ifdef TOPPERS_SUPPORT_MUTEX
	0U,						/* bpriority */
#endif /* TOPPERS_SUPPORT_MUTEX */
	0U,						/* priority */
	false,					/* acqeue */
	false,					/* wupque */
	true,					/* enatex */
	0U,						/* texprn */
	NULL,					/* p_winifo */
#ifdef TOPPERS_SUPPORT_MUTEX
	{ NULL, NULL },			/* mutex_queue */
#endif /* TOPPERS_SUPPORT_MUTEX */
	{ NULL, NULL }			/* tskctxb */
};
