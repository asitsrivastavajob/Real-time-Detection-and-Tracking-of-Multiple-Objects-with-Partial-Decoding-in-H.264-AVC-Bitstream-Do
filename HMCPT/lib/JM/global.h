
/*!
 ************************************************************************
 *  \file
 *     global.h
 *  \brief
 *     global definitions for for H.264 decoder.
 *  \author
 *     Copyright (C) 1999  Telenor Satellite Services,Norway
 *                         Ericsson Radio Systems, Sweden
 *
 *     Inge Lille-Langoy               <inge.lille-langoy@telenor.com>
 *
 *     Telenor Satellite Services
 *     Keysers gt.13                       tel.:   +47 23 13 86 98
 *     N-0130 Oslo,Norway                  fax.:   +47 22 77 79 80
 *
 *     Rickard Sjoberg                 <rickard.sjoberg@era.ericsson.se>
 *
 *     Ericsson Radio Systems
 *     KI/ERA/T/VV
 *     164 80 Stockholm, Sweden
 *
 ************************************************************************
 */

#ifdef __cplusplus
extern "C" { //visible only to a C++ compiler
#endif

#ifndef _GLOBAL_H_
#define _GLOBAL_H_

#include <stdio.h>                              //!< for FILE
#include <time.h>
#include <sys/timeb.h>
#include "defines.h"
#include "parsetcommon.h"

#ifdef WIN32
#define  snprintf _snprintf
#define  open     _open
#define  close    _close
#define  read     _read
#define  write    _write
#define  lseek    _lseeki64
#define  fsync    _commit
#define  OPENFLAGS_WRITE _O_WRONLY|_O_CREAT|_O_BINARY|_O_TRUNC
#define  OPEN_PERMISSIONS _S_IREAD | _S_IWRITE
#define  OPENFLAGS_READ  _O_RDONLY|_O_BINARY
#else
#define  OPENFLAGS_WRITE O_WRONLY|O_CREAT|O_TRUNC
#define  OPENFLAGS_READ  O_RDONLY
#define  OPEN_PERMISSIONS S_IRUSR | S_IWUSR
#endif

typedef unsigned char   byte;                   //!<  8 bit unsigned
typedef int             int32;
typedef unsigned int    u_int32;

#define imgpel unsigned short

#if defined(WIN32) && !defined(__GNUC__)
  typedef __int64   int64;
#ifndef INT64_MIN
# define INT64_MIN        (-9223372036854775807i64 - 1i64)
#endif
#else
  typedef long long int64;
#ifndef INT64_MIN
# define INT64_MIN        (-9223372036854775807LL - 1LL)
#endif
#endif


pic_parameter_set_rbsp_t *active_pps;
seq_parameter_set_rbsp_t *active_sps;

// global picture format dependend buffers, mem allocation in decod.c ******************
int  **refFrArr;                                //!< Array for reference frames of each block

imgpel **imgY_ref;                                //!< reference frame find snr
imgpel ***imgUV_ref;

int  ReMapRef[20];
// B pictures
int  Bframe_ctr;
int  frame_no;

int  g_nFrame;

// For MB level frame/field coding
int  TopFieldForSkip_Y[16][16];
int  TopFieldForSkip_UV[2][16][16];

int  InvLevelScale4x4Luma_Intra[6][4][4];
int  InvLevelScale4x4Chroma_Intra[2][6][4][4];

int  InvLevelScale4x4Luma_Inter[6][4][4];
int  InvLevelScale4x4Chroma_Inter[2][6][4][4];

int  InvLevelScale8x8Luma_Intra[6][8][8];

int  InvLevelScale8x8Luma_Inter[6][8][8];

int  *qmatrix[8];

#define ET_SIZE 300      //!< size of error text buffer
char errortext[ET_SIZE]; //!< buffer for error message for exit with error()

//Added by Wonsang You at May 14, 2007
#define ERROR_GROUP					0
#define CANDIDATE_GROUP				1
#define OBJECT_GROUP				2
#define HIDDEN_GROUP				3
#define UNKNOWN_LABEL				20
#define MAX_BUF_NUM					20
#define INTRA_PERIOD				4
#define HOR_DECODING_MARGIN			8
#define VER_DECODING_MARGIN			8
#define DELTA_WIDTH_MARGIN			2
#define DELTA_HEIGHT_MARGIN			2
#define DIFF_WIDTH_MARGIN			32
#define DIFF_HEIGHT_MARGIN			32
#define BKD_STR_TOL					20

typedef struct
{
	int				DetectFrame;
	double			*OccurProb;
	int				*FrmGroupIdx;
	int				*PosX;
	int				*PosY;
	int				*Width;
	int				*Height;
	int				Status;
	int				CheckCnt;
	int				ChkOn;
	int				DominantGroupIdx;
	int				*MbNum;
	int				OccurCnt;
	int				FrameCnt;
	int				ObjectFrame;
} GroupDescriptor;

FILE* SPA_FILE				;
int output_spatial_noise_flag;
int output_group_buffer_flag;
FILE* BUF_FILE				;
int trajectory_optimization_flag;
int time_measure_flag		;
int partial_decode_flag		;
int output_trajectory_flag	;
FILE* TRA_FILE				;
int bkd_ref_flag			;
int gbuf_Status[MAX_BUF_NUM][4];
unsigned char*** frm_buf	;
int object_recognition_flag	;
FILE* MTR_FILE				;
int extract_trajectory_flag	;
double occur_th				;
int decision_window_size	;
int max_buf_group_num		;
GroupDescriptor gbuf[MAX_BUF_NUM];
int label_size[UNKNOWN_LABEL+1];
int display_group_idx[UNKNOWN_LABEL];
int **mblabel				;
int **DrawBlockFlag			;
int multiple_block_drawing_flag;
int draw_textured_motion_blocks;
int draw_motion_blocks		;
int draw_textured_blocks	;
int residual_reverse_contrast_flag;
int DrawMbTypeEnb[16]		;
double th_textured			;
int segmentation_flag		;
int decode_residue_flag		;
unsigned char** frm_mbt		;
unsigned char** frm_omv		;
FILE* MBT_FILE				;
int *MbType					;
int **B8Mode				;
int read_mb_type_flag		;
unsigned char** res_str		;
FILE* RES_FILE				;
FILE* BKS_FILE				;
unsigned char** bkd_str		;
unsigned char** BkdBuf		;
int block_point_flag		;
FILE* OMV_FILE				;
int res_anal_flag			;
FILE* RESANAL_FILE			;
//unsigned char ***dec_res	;
unsigned char ***curr_res	;
int res[16][16]				;                             // residual 4x4 block
int extract_flag			;
int tracking_flag			;
int analysis_mode			;
int video_save_flag			;
int modify_tracking_flag	;
int full_decode_flag		;
int occlusion_handling		;
double AvgDiffPE			;
double AvgDiffPF			;
double th_form				;
double th_texture			;
double th_mvd				;
double th_reliability		;
int occlusion_flag			;
int iheight					;
int iwidth					;
int start_frame_num			;
int first_frame				;
FILE *WT_FILE				;
FILE *ET_FILE				;
FILE *OT_FILE				;
FILE *TT_FILE				;
double w0					;
double wt					;
double wm					;
double wf					;
int intra_search_err		;
double **pred_con			;
int max_motion_picture_num	;
unsigned char ***upd_con	;
int search_half_interval	;
int sad_half_interval		;
int dec_search_err			;
int init_con_nr				;
int motion_picture_num		;
int *blk_dec_enb			;
int **blk_list				;
double ***upd_mv			;
double ***dec_mv			;
unsigned char ***curr_frm	;
unsigned char ***prev_frm	;
double **object_center		;
//unsigned char ***dec_pic	;
//int picture_num			;
//Added-End


/***********************************************************************
 * T y p e    d e f i n i t i o n s    f o r    T M L
 ***********************************************************************
 */

//! Data Partitioning Modes
typedef enum
{
  PAR_DP_1,    //!< no data partitioning is supported
  PAR_DP_3,    //!< data partitioning with 3 partitions
} PAR_DP_TYPE;


//! Output File Types
typedef enum
{
  PAR_OF_ANNEXB,   //!< Current TML description
  PAR_OF_RTP,   //!< RTP Packet Output format
//  PAR_OF_IFF    //!< Interim File Format
} PAR_OF_TYPE;

//! Boolean Type
/*typedef enum {
  FALSE,
  TRUE
} Boolean;
*/
//! definition of H.264 syntax elements
typedef enum {
  SE_HEADER,
  SE_PTYPE,
  SE_MBTYPE,
  SE_REFFRAME,
  SE_INTRAPREDMODE,
  SE_MVD,
  SE_CBP_INTRA,
  SE_LUM_DC_INTRA,
  SE_CHR_DC_INTRA,
  SE_LUM_AC_INTRA,
  SE_CHR_AC_INTRA,
  SE_CBP_INTER,
  SE_LUM_DC_INTER,
  SE_CHR_DC_INTER,
  SE_LUM_AC_INTER,
  SE_CHR_AC_INTER,
  SE_DELTA_QUANT_INTER,
  SE_DELTA_QUANT_INTRA,
  SE_BFRAME,
  SE_EOS,
  SE_MAX_ELEMENTS //!< number of maximum syntax elements, this MUST be the last one!
} SE_type;        // substituting the definitions in element.h


typedef enum {
  INTER_MB,
  INTRA_MB_4x4,
  INTRA_MB_16x16
} IntraInterDecision;

typedef enum {
  BITS_TOTAL_MB,
  BITS_HEADER_MB,
  BITS_INTER_MB,
  BITS_CBP_MB,
  BITS_COEFF_Y_MB,
  BITS_COEFF_UV_MB,
  MAX_BITCOUNTER_MB
} BitCountType;

typedef enum {
  NO_SLICES,
  FIXED_MB,
  FIXED_RATE,
  CALLBACKA,
  FMO
} SliceMode;


typedef enum {
  UVLC,
  CABAC
} SymbolMode;

typedef enum {
 LIST_0=0,
 LIST_1=1
} Lists;


typedef enum {
  FRAME,
  TOP_FIELD,
  BOTTOM_FIELD
} PictureStructure;           //!< New enum for field processing


typedef enum {
  P_SLICE = 0,
  B_SLICE,
  I_SLICE,
  SP_SLICE,
  SI_SLICE
} SliceType;

/***********************************************************************
 * D a t a    t y p e s   f o r  C A B A C
 ***********************************************************************
 */

//! struct to characterize the state of the arithmetic coding engine
typedef struct
{
  unsigned int    Dlow, Drange;
  unsigned int    Dvalue;
  unsigned int    Dbuffer;
  int             Dbits_to_go;
  byte            *Dcodestrm;
  int             *Dcodestrm_len;
} DecodingEnvironment;

typedef DecodingEnvironment *DecodingEnvironmentPtr;

//! struct for context management
typedef struct
{
  unsigned short state;         // index into state-table CP  
  unsigned char  MPS;           // Least Probable Symbol 0/1 CP
} BiContextType;

typedef BiContextType *BiContextTypePtr;


/**********************************************************************
 * C O N T E X T S   F O R   T M L   S Y N T A X   E L E M E N T S
 **********************************************************************
 */

#define NUM_MB_TYPE_CTX  11
#define NUM_B8_TYPE_CTX  9
#define NUM_MV_RES_CTX   10
#define NUM_REF_NO_CTX   6
#define NUM_DELTA_QP_CTX 4
#define NUM_MB_AFF_CTX 4
#define NUM_TRANSFORM_SIZE_CTX 3


typedef struct
{
  BiContextType mb_type_contexts [4][NUM_MB_TYPE_CTX];
  BiContextType b8_type_contexts [2][NUM_B8_TYPE_CTX];
  BiContextType mv_res_contexts  [2][NUM_MV_RES_CTX];
  BiContextType ref_no_contexts  [2][NUM_REF_NO_CTX];
  BiContextType delta_qp_contexts[NUM_DELTA_QP_CTX];
  BiContextType mb_aff_contexts  [NUM_MB_AFF_CTX];
  BiContextType transform_size_contexts [NUM_TRANSFORM_SIZE_CTX];

} MotionInfoContexts;

#define NUM_IPR_CTX    2
#define NUM_CIPR_CTX   4
#define NUM_CBP_CTX    4
#define NUM_BCBP_CTX   4
#define NUM_MAP_CTX   15
#define NUM_LAST_CTX  15
#define NUM_ONE_CTX    5
#define NUM_ABS_CTX    5


typedef struct
{
  BiContextType  ipr_contexts [NUM_IPR_CTX];
  BiContextType  cipr_contexts[NUM_CIPR_CTX]; 
  BiContextType  cbp_contexts [3][NUM_CBP_CTX];
  BiContextType  bcbp_contexts[NUM_BLOCK_TYPES][NUM_BCBP_CTX];
  BiContextType  map_contexts [NUM_BLOCK_TYPES][NUM_MAP_CTX];
  BiContextType  last_contexts[NUM_BLOCK_TYPES][NUM_LAST_CTX];
  BiContextType  one_contexts [NUM_BLOCK_TYPES][NUM_ONE_CTX];
  BiContextType  abs_contexts [NUM_BLOCK_TYPES][NUM_ABS_CTX];
  BiContextType  fld_map_contexts [NUM_BLOCK_TYPES][NUM_MAP_CTX];
  BiContextType  fld_last_contexts[NUM_BLOCK_TYPES][NUM_LAST_CTX];
} TextureInfoContexts;


//*********************** end of data type definition for CABAC *******************

/***********************************************************************
 * N e w   D a t a    t y p e s   f o r    T M L
 ***********************************************************************
 */

struct img_par;
struct inp_par;
struct stat_par;

/*! Buffer structure for decoded referenc picture marking commands */
typedef struct DecRefPicMarking_s
{
  int memory_management_control_operation;
  int difference_of_pic_nums_minus1;
  int long_term_pic_num;
  int long_term_frame_idx;
  int max_long_term_frame_idx_plus1;
  struct DecRefPicMarking_s *Next;
} DecRefPicMarking_t;

//! Syntaxelement
typedef struct syntaxelement
{
  int           type;                  //!< type of syntax element for data part.
  int           value1;                //!< numerical value of syntax element
  int           value2;                //!< for blocked symbols, e.g. run/level
  int           len;                   //!< length of code
  int           inf;                   //!< info part of UVLC code
  unsigned int  bitpattern;            //!< UVLC bitpattern
  int           context;               //!< CABAC context
  int           k;                     //!< CABAC context for coeff_count,uv

#if TRACEA
  #define       TRACESTRING_SIZE 100           //!< size of trace string
  char          tracestring[TRACESTRING_SIZE]; //!< trace string
#endif

  //! for mapping of UVLC to syntaxElement
  void    (*mapping)(int len, int info, int *value1, int *value2);
  //! used for CABAC: refers to actual coding method of each individual syntax element type
  void  (*reading)(struct syntaxelement *, struct inp_par *, struct img_par *, DecodingEnvironmentPtr);

} SyntaxElement;

//! Macroblock
typedef struct macroblock
{
  int           qp;
  int           slice_nr;
  int           delta_quant;          //!< for rate control
  
  struct macroblock   *mb_available_up;   //!< pointer to neighboring MB (CABAC)
  struct macroblock   *mb_available_left; //!< pointer to neighboring MB (CABAC)

  // some storage of macroblock syntax elements for global access
  int           mb_type;
  int           mvd[2][BLOCK_MULTIPLE][BLOCK_MULTIPLE][2];      //!< indices correspond to [forw,backw][block_y][block_x][x,y]
  int           cbp;
  int64         cbp_blk ;
  int64         cbp_bits;

  int           is_skip;

  int           i16mode;
  int           b8mode[4];
  int           b8pdir[4];
  int           ei_flag;

  int           LFDisableIdc;
  int           LFAlphaC0Offset;
  int           LFBetaOffset;

  int           c_ipred_mode;       //!< chroma intra prediction mode
  int           mb_field;

  int           skip_flag;

  int mbAddrA, mbAddrB, mbAddrC, mbAddrD;
  int mbAvailA, mbAvailB, mbAvailC, mbAvailD;

  int           luma_transform_size_8x8_flag;
  int           NoMbPartLessThan8x8Flag;
} Macroblock;

//! Bitstream
typedef struct
{
  // CABAC Decoding
  int           read_len;           //!< actual position in the codebuffer, CABAC only
  int           code_len;           //!< overall codebuffer length, CABAC only
  // UVLC Decoding
  int           frame_bitoffset;    //!< actual position in the codebuffer, bit-oriented, UVLC only
  int           bitstream_length;   //!< over codebuffer lnegth, byte oriented, UVLC only
  // ErrorConcealment
  byte          *streamBuffer;      //!< actual codebuffer for read bytes
  int           ei_flag;            //!< error indication, 0: no error, else unspecified error
} Bitstream;

//! DataPartition
typedef struct datapartition
{

  Bitstream           *bitstream;
  DecodingEnvironment de_cabac;

  int     (*readSyntaxElement)(SyntaxElement *, struct img_par *, struct inp_par *, struct datapartition *);
          /*!< virtual function;
               actual method depends on chosen data partition and
               entropy coding method  */
} DataPartition;

//! Slice
typedef struct
{
  int                 ei_flag;       //!< 0 if the partArr[0] contains valid information
  int                 qp;
  int                 slice_qp_delta;
  int                 picture_type;  //!< picture type
  PictureStructure    structure;     //!< Identify picture structure type
  int                 start_mb_nr;   //!< MUST be set by NAL even in case of ei_flag == 1
  int                 max_part_nr;
  int                 dp_mode;       //!< data partioning mode
  int                 next_header;
//  int                 last_mb_nr;    //!< only valid when entropy coding == CABAC
  DataPartition       *partArr;      //!< array of partitions
  MotionInfoContexts  *mot_ctx;      //!< pointer to struct of context models for use in CABAC
  TextureInfoContexts *tex_ctx;      //!< pointer to struct of context models for use in CABAC
  
  int                 ref_pic_list_reordering_flag_l0;
  int                 *reordering_of_pic_nums_idc_l0;
  int                 *abs_diff_pic_num_minus1_l0;
  int                 *long_term_pic_idx_l0;
  int                 ref_pic_list_reordering_flag_l1;
  int                 *reordering_of_pic_nums_idc_l1;
  int                 *abs_diff_pic_num_minus1_l1;
  int                 *long_term_pic_idx_l1;

  int     (*readSlice)(struct img_par *, struct inp_par *);

  int                 LFDisableIdc;     //!< Disable loop filter on slice
  int                 LFAlphaC0Offset;  //!< Alpha and C0 offset for filtering slice
  int                 LFBetaOffset;     //!< Beta offset for filtering slice

  int                 pic_parameter_set_id;   //!<the ID of the picture parameter set the slice is reffering to

} Slice;

//****************************** ~DM ***********************************

// image parameters
typedef struct img_par
{
  int number;                                 //!< frame number
  unsigned current_mb_nr; // bitstream order
  unsigned num_dec_mb;
  int current_slice_nr;
  int *intra_block;
  int tr;                                     //!< temporal reference, 8 bit, wrapps at 255
  int qp;                                     //!< quant for the current frame
  int qpsp;                                   //!< quant for SP-picture predicted frame
  int sp_switch;                              //!< 1 for switching sp, 0 for normal sp
  int direct_spatial_mv_pred_flag;            //!< 1 for Spatial Direct, 0 for Temporal
  int type;                                   //!< image type INTER/INTRA
  int width;
  int height;
  int width_cr;                               //!< width chroma
  int height_cr;                              //!< height chroma
  int mb_y;
  int mb_x;
  int block_y;
  int pix_y;
  int pix_x;
  int pix_c_y;
  int block_x;
  int pix_c_x;

  int allrefzero;
  imgpel mpr[16][16];                         //!< predicted block
  int mvscale[6][MAX_REFERENCE_PICTURES];
  int m7[16][16];                             //!< final 4x4 block. Extended to 16x16 for ABT
  int cof[4][12][4][4];                       //!< correction coefficients from predicted   
  int cofu[16];                                                                             
  int **ipredmode;                            //!< prediction type [90][74]
  int *quad;
  int ***nz_coeff;
  int **siblock;
  int cod_counter;                            //!< Current count of number of skipped macroblocks in a row

  int newframe;

  int structure;                               //!< Identify picture structure type
  int pstruct_next_P;

  // B pictures
  Slice       *currentSlice;                   //!< pointer to current Slice data struct
  Macroblock          *mb_data;                //!< array containing all MBs of a whole frame
  int subblock_x;
  int subblock_y;
  int is_intra_block;
  int is_v_block;

  // For MB level frame/field coding
  int MbaffFrameFlag;

  // for signalling to the neighbour logic that this is a deblocker call
  int DeblockCall;

  int **field_anchor;

  DecRefPicMarking_t *dec_ref_pic_marking_buffer;                    //!< stores the memory management control operations

  int disposable_flag;                          //!< flag for disposable frame, 1:disposable
  int num_ref_idx_l0_active;             //!< number of forward reference
  int num_ref_idx_l1_active;             //!< number of backward reference

  int slice_group_change_cycle;
  // JVT-D101
  int redundant_slice_flag; 
  int redundant_pic_cnt; 

  int explicit_B_prediction;

  unsigned int pre_frame_num;           //!< store the frame_num in the last decoded slice. For detecting gap in frame_num.

  // End JVT-D101
  // POC200301: from unsigned int to int
           int toppoc;      //poc for this top field // POC200301
           int bottompoc;   //poc of bottom field of frame
           int framepoc;    //poc of this frame // POC200301
  unsigned int frame_num;   //frame_num for this frame
  unsigned int field_pic_flag;
  unsigned int bottom_field_flag;
  
  //the following is for slice header syntax elements of poc
  // for poc mode 0.
  unsigned int pic_order_cnt_lsb;
           int delta_pic_order_cnt_bottom;
  // for poc mode 1.
           int delta_pic_order_cnt[3];

  // ////////////////////////
  // for POC mode 0:
    signed int PrevPicOrderCntMsb;
  unsigned int PrevPicOrderCntLsb;
    signed int PicOrderCntMsb;

  // for POC mode 1:
  unsigned int AbsFrameNum;
    signed int ExpectedPicOrderCnt, PicOrderCntCycleCnt, FrameNumInPicOrderCntCycle;
  unsigned int PreviousFrameNum, FrameNumOffset;
           int ExpectedDeltaPerPicOrderCntCycle;
           int PreviousPOC, ThisPOC;
           int PreviousFrameNumOffset;
  // /////////////////////////

  //weighted prediction
  unsigned int luma_log2_weight_denom;
  unsigned int chroma_log2_weight_denom;
  int ***wp_weight;  // weight in [list][index][component] order
  int ***wp_offset;  // offset in [list][index][component] order
  int ****wbp_weight; //weight in [list][fw_index][bw_index][component] order
  int wp_round_luma;
  int wp_round_chroma;
  unsigned int apply_weights;

  int idr_flag;
  int nal_reference_idc;                       //!< nal_reference_idc from NAL unit

  int idr_pic_id;

  int MaxFrameNum;

  unsigned PicWidthInMbs;
  unsigned PicHeightInMapUnits;
  unsigned FrameHeightInMbs;
  unsigned PicHeightInMbs;
  unsigned PicSizeInMbs;
  unsigned FrameSizeInMbs;
  unsigned oldFrameSizeInMbs;

  int no_output_of_prior_pics_flag;
  int long_term_reference_flag;
  int adaptive_ref_pic_buffering_flag;

  int last_has_mmco_5;
  int last_pic_bottom_field;

  int model_number;

  // Fidelity Range Extensions Stuff
  int pic_unit_bitsize_on_disk;
  int bitdepth_luma;
  int bitdepth_chroma;
  int bitdepth_luma_qp_scale;
  int bitdepth_chroma_qp_scale;
  unsigned int dc_pred_value;                 //!< value for DC prediction (depends on pel bit depth)
  int max_imgpel_value;                       //!< max value that one luma picture element (pixel) can take (depends on pic_unit_bitdepth)
  int max_imgpel_value_uv;                    //!< max value that one chroma picture element (pixel) can take (depends on pic_unit_bitdepth)
  int Transform8x8Mode;        
  int profile_idc;              
  int yuv_format;
  int lossless_qpprime_flag;
  int num_blk8x8_uv;
  int num_cdc_coeff;
  int mb_cr_size_x;
  int mb_cr_size_y;
  
  int idr_psnr_number;
  int psnr_number;

  time_t ltime_start;               // for time measurement
  time_t ltime_end;                 // for time measurement

  // Residue Color Transform
  int residue_transform_flag;

#ifdef WIN32
  struct _timeb tstruct_start;
  struct _timeb tstruct_end;
#else
  struct timeb tstruct_start;
  struct timeb tstruct_end;
#endif

  // picture error concealment
  int last_ref_pic_poc;
  int ref_poc_gap;
  int poc_gap;
  int conceal_mode;
  int earlier_missing_poc;
  unsigned int frame_to_conceal;
  int IDR_concealment_flag;
  int conceal_slice_type;

} ImageParameters;

extern ImageParameters *img;
extern struct snr_par  *snr;

// signal to noise ratio parameters
struct snr_par
{
  int   frame_ctr;
  float snr_y;                                 //!< current Y SNR
  float snr_u;                                 //!< current U SNR
  float snr_v;                                 //!< current V SNR
  float snr_y1;                                //!< SNR Y(dB) first frame
  float snr_u1;                                //!< SNR U(dB) first frame
  float snr_v1;                                //!< SNR V(dB) first frame
  float snr_ya;                                //!< Average SNR Y(dB) remaining frames
  float snr_ua;                                //!< Average SNR U(dB) remaining frames
  float snr_va;                                //!< Average SNR V(dB) remaining frames
  float sse_y;                                 //!< SSE Y
  float sse_u;                                 //!< SSE U
  float sse_v;                                 //!< SSE V
  float msse_y;                                //!< Average SSE Y
  float msse_u;                                //!< Average SSE U
  float msse_v;                                //!< Average SSE V
};

int tot_time;

// input parameters from configuration file
struct inp_par
{
  char infile[100];                       //!< H.264 inputfile
  char outfile[100];                      //!< Decoded YUV 4:2:0 output
  char reffile[100];                      //!< Optional YUV 4:2:0 reference file for SNR measurement
  int FileFormat;                         //!< File format of the Input file, PAR_OF_ANNEXB or PAR_OF_RTP
  int ref_offset;
  int poc_scale;
  int write_uv;

#ifdef _LEAKYBUCKET_
  unsigned long R_decoder;                //!< Decoder Rate in HRD Model
  unsigned long B_decoder;                //!< Decoder Buffer size in HRD model
  unsigned long F_decoder;                //!< Decoder Initial buffer fullness in HRD model
  char LeakyBucketParamFile[100];         //!< LeakyBucketParamFile
#endif

  // picture error concealment
  int conceal_mode;
  int ref_poc_gap;
  int poc_gap;

};

extern struct inp_par *input;

typedef struct pix_pos
{
  int available;
  int mb_addr;
  int x;
  int y;
  int pos_x;
  int pos_y;
} PixelPos;

typedef struct old_slice_par
{
   unsigned field_pic_flag;
   unsigned bottom_field_flag;
   unsigned frame_num;
   int nal_ref_idc;
   unsigned pic_oder_cnt_lsb;
   int delta_pic_oder_cnt_bottom;
   int delta_pic_order_cnt[2];
   int idr_flag;
   int idr_pic_id;
   int pps_id;
} OldSliceParams;

extern OldSliceParams old_slice;

// files
int p_out;                    //!< file descriptor to output YUV file
//FILE *p_out2;                    //!< pointer to debug output YUV file
int p_ref;                    //!< pointer to input original reference YUV file file

FILE *p_log;                    //!< SNR file

#if TRACEA
FILE *p_trace;
#endif

// Residue Color Transform
int mprRGB[3][16][16];
int rec_res[3][16][16];

// prototypes
void init_conf(struct inp_par *inp, char *config_filename);
void report(struct inp_par *inp, struct img_par *img, struct snr_par *snr);
void init(struct img_par *img);

void malloc_slice(struct inp_par *inp, struct img_par *img);
void free_slice(struct inp_par *inp, struct img_par *img);

int  decode_one_frame(struct img_par *img,struct inp_par *inp, struct snr_par *snr);
void init_picture(struct img_par *img, struct inp_par *inp);
void exit_picture();

int  read_new_slice();
void decode_one_slice(struct img_par *img,struct inp_par *inp);

void start_macroblock(struct img_par *img,struct inp_par *inp, int CurrentMBInScanOrder);
int  read_one_macroblock(struct img_par *img,struct inp_par *inp);
void read_ipred_modes(struct img_par *img,struct inp_par *inp);
int  decode_one_macroblock(struct img_par *img,struct inp_par *inp);
int  exit_macroblock(struct img_par *img,struct inp_par *inp, int eos_bit);
void decode_ipcm_mb(struct img_par *img);


void readMotionInfoFromNAL (struct img_par *img,struct inp_par *inp);
void readCBPandCoeffsFromNAL(struct img_par *img,struct inp_par *inp);
void readIPCMcoeffsFromNAL(struct img_par *img, struct inp_par *inp, struct datapartition *dP);

void readLumaCoeff8x8_CABAC (struct img_par *img,struct inp_par *inp, int b8);
void itrans8x8(struct img_par *img, int ioff, int joff);

void copyblock_sp(struct img_par *img,int block_x,int block_y);
void itrans_sp_chroma(struct img_par *img,int ll);
void itrans(struct img_par *img,int ioff,int joff,int i0,int j0, int chroma);
void itrans_sp(struct img_par *img,int ioff,int joff,int i0,int j0);
int  intrapred(struct img_par *img,int ioff,int joff,int i4,int j4);
void itrans_2(struct img_par *img);
int  intrapred_luma_16x16(struct img_par *img,int predmode);
void intrapred_chroma(struct img_par *img, int uv);
int  sign(int a , int b);

// SLICE function pointers
int  (*nal_startcode_follows) ();

// NAL functions TML/CABAC bitstream
int  uvlc_startcode_follows();
int  cabac_startcode_follows();
void free_Partition(Bitstream *currStream);

// ErrorConcealment
void reset_ec_flags();

void error(char *text, int code);
int  is_new_picture();
void init_old_slice();

// dynamic mem allocation
int  init_global_buffers();
void free_global_buffers();

void frame_postprocessing(struct img_par *img, struct inp_par *inp);
void field_postprocessing(struct img_par *img, struct inp_par *inp);
int  bottom_field_picture(struct img_par *img,struct inp_par *inp);
void decode_slice(struct img_par *img,struct inp_par *inp, int current_header);

//Added by Wonsang You at FEB 2, 2007
void free_buffer_PD();
void alloc_buffer_PD();
double clipx(double x);
double clipy(double y);
double clipbx(double bx);
double clipby(double by);
int first_partial_decode_one_frame(struct img_par *img,struct inp_par *inp, struct snr_par *snr);
int last_partial_decode_one_frame(struct img_par *img,struct inp_par *inp, struct snr_par *snr);
int partial_decode_one_frame(struct img_par *img,struct inp_par *inp, struct snr_par *snr);
int partial_read_new_slice();
void partial_decode_slice(struct img_par *img,struct inp_par *inp, int current_header);
void partial_decode_one_slice(struct img_par *img,struct inp_par *inp);
int partial_decode_one_macroblock(struct img_par *img,struct inp_par *inp, int *BlkList);
int pred_pos();
int gen_decblock_list();
void trans_block_idx(int block_x, int block_y, int *mb_nr, int *x4_nr);
void trans_block_coordinate(int mb_nr, int x4_nr, int *block_x, int *block_y);
void get_ref_blocks(int block_x, int block_y, int **neighbor);
int decide_pos();
void set_buffer_PD();
//Added-End


int RBSPtoSODB(byte *streamBuffer, int last_byte_pos);
int EBSPtoRBSP(byte *streamBuffer, int end_bytepos, int begin_bytepos);

// For MB level frame/field coding
void init_super_macroblock(struct img_par *img,struct inp_par *inp);
void exit_super_macroblock(struct img_par *img,struct inp_par *inp);
int  decode_super_macroblock(struct img_par *img,struct inp_par *inp);
void decode_one_Copy_topMB(struct img_par *img,struct inp_par *inp);

void SetOneRefMV(struct img_par* img);
int peekSyntaxElement_UVLC(SyntaxElement *sym, struct img_par *img, struct inp_par *inp, struct datapartition *dP);

void fill_wp_params(struct img_par *img);

void reset_wp_params(struct img_par *img);

void FreePartition (DataPartition *dp, int n);
DataPartition *AllocPartition(int n);

void tracebits2(const char *trace_str, int len, int info);

void init_decoding_engine_IPCM(struct img_par *img);
void readIPCMBytes_CABAC(SyntaxElement *sym, Bitstream *currStream);

#endif

// For Q-matrix
void AssignQuantParam(pic_parameter_set_rbsp_t* pps, seq_parameter_set_rbsp_t* sps);
void CalculateQuantParam(void);
void CalculateQuant8Param(void);

#ifdef __cplusplus
} //visible only to a C++ compiler
#endif