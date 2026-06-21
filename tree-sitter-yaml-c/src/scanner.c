#include "tree_sitter/parser.h"
#include <assert.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

/* ---- Inlined from schema.generated.cc (namespace removed) ---- */

static const int8_t SCH_STT_FRZ = -1;

typedef enum {
    RS_STR,
    RS_INT,
    RS_NUL,
    RS_BOL,
    RS_FLT,
} ResultSchema;

static int8_t adv_sch_stt(int8_t sch_stt, int32_t cur_chr, ResultSchema *rlt_sch) {
    switch (sch_stt) {
        case -1: break;
        case 0:
            if (cur_chr == '.') {*rlt_sch = RS_STR; return 6;}
            if (cur_chr == '0') {*rlt_sch = RS_INT; return 37;}
            if (cur_chr == 'F') {*rlt_sch = RS_STR; return 2;}
            if (cur_chr == 'N') {*rlt_sch = RS_STR; return 16;}
            if (cur_chr == 'T') {*rlt_sch = RS_STR; return 13;}
            if (cur_chr == 'f') {*rlt_sch = RS_STR; return 17;}
            if (cur_chr == 'n') {*rlt_sch = RS_STR; return 29;}
            if (cur_chr == 't') {*rlt_sch = RS_STR; return 26;}
            if (cur_chr == '~') {*rlt_sch = RS_NUL; return 35;}
            if (cur_chr == '+' || cur_chr == '-') {*rlt_sch = RS_STR; return 1;}
            if ('1' <= cur_chr && cur_chr <= '9') {*rlt_sch = RS_INT; return 38;}
            break;
        case 1:
            if (cur_chr == '.') {*rlt_sch = RS_STR; return 7;}
            if ('0' <= cur_chr && cur_chr <= '9') {*rlt_sch = RS_INT; return 38;}
            break;
        case 2:
            if (cur_chr == 'A') {*rlt_sch = RS_STR; return 9;}
            if (cur_chr == 'a') {*rlt_sch = RS_STR; return 22;}
            break;
        case 3:
            if (cur_chr == 'A') {*rlt_sch = RS_STR; return 12;}
            if (cur_chr == 'a') {*rlt_sch = RS_STR; return 12;}
            break;
        case 4:
            if (cur_chr == 'E') {*rlt_sch = RS_BOL; return 36;}
            break;
        case 5:
            if (cur_chr == 'F') {*rlt_sch = RS_FLT; return 41;}
            break;
        case 6:
            if (cur_chr == 'I') {*rlt_sch = RS_STR; return 11;}
            if (cur_chr == 'N') {*rlt_sch = RS_STR; return 3;}
            if (cur_chr == 'i') {*rlt_sch = RS_STR; return 24;}
            if (cur_chr == 'n') {*rlt_sch = RS_STR; return 18;}
            if ('0' <= cur_chr && cur_chr <= '9') {*rlt_sch = RS_FLT; return 42;}
            break;
        case 7:
            if (cur_chr == 'I') {*rlt_sch = RS_STR; return 11;}
            if (cur_chr == 'i') {*rlt_sch = RS_STR; return 24;}
            if ('0' <= cur_chr && cur_chr <= '9') {*rlt_sch = RS_FLT; return 42;}
            break;
        case 8:
            if (cur_chr == 'L') {*rlt_sch = RS_NUL; return 35;}
            break;
        case 9:
            if (cur_chr == 'L') {*rlt_sch = RS_STR; return 14;}
            break;
        case 10:
            if (cur_chr == 'L') {*rlt_sch = RS_STR; return 8;}
            break;
        case 11:
            if (cur_chr == 'N') {*rlt_sch = RS_STR; return 5;}
            if (cur_chr == 'n') {*rlt_sch = RS_STR; return 20;}
            break;
        case 12:
            if (cur_chr == 'N') {*rlt_sch = RS_FLT; return 41;}
            break;
        case 13:
            if (cur_chr == 'R') {*rlt_sch = RS_STR; return 15;}
            if (cur_chr == 'r') {*rlt_sch = RS_STR; return 28;}
            break;
        case 14:
            if (cur_chr == 'S') {*rlt_sch = RS_STR; return 4;}
            break;
        case 15:
            if (cur_chr == 'U') {*rlt_sch = RS_STR; return 4;}
            break;
        case 16:
            if (cur_chr == 'U') {*rlt_sch = RS_STR; return 10;}
            if (cur_chr == 'u') {*rlt_sch = RS_STR; return 23;}
            break;
        case 17:
            if (cur_chr == 'a') {*rlt_sch = RS_STR; return 22;}
            break;
        case 18:
            if (cur_chr == 'a') {*rlt_sch = RS_STR; return 25;}
            break;
        case 19:
            if (cur_chr == 'e') {*rlt_sch = RS_BOL; return 36;}
            break;
        case 20:
            if (cur_chr == 'f') {*rlt_sch = RS_FLT; return 41;}
            break;
        case 21:
            if (cur_chr == 'l') {*rlt_sch = RS_NUL; return 35;}
            break;
        case 22:
            if (cur_chr == 'l') {*rlt_sch = RS_STR; return 27;}
            break;
        case 23:
            if (cur_chr == 'l') {*rlt_sch = RS_STR; return 21;}
            break;
        case 24:
            if (cur_chr == 'n') {*rlt_sch = RS_STR; return 20;}
            break;
        case 25:
            if (cur_chr == 'n') {*rlt_sch = RS_FLT; return 41;}
            break;
        case 26:
            if (cur_chr == 'r') {*rlt_sch = RS_STR; return 28;}
            break;
        case 27:
            if (cur_chr == 's') {*rlt_sch = RS_STR; return 19;}
            break;
        case 28:
            if (cur_chr == 'u') {*rlt_sch = RS_STR; return 19;}
            break;
        case 29:
            if (cur_chr == 'u') {*rlt_sch = RS_STR; return 23;}
            break;
        case 30:
            if (cur_chr == '+' || cur_chr == '-') {*rlt_sch = RS_STR; return 32;}
            if ('0' <= cur_chr && cur_chr <= '9') {*rlt_sch = RS_FLT; return 43;}
            break;
        case 31:
            if ('0' <= cur_chr && cur_chr <= '7') {*rlt_sch = RS_INT; return 39;}
            break;
        case 32:
            if ('0' <= cur_chr && cur_chr <= '9') {*rlt_sch = RS_FLT; return 43;}
            break;
        case 33:
            if (('0' <= cur_chr && cur_chr <= '9') ||
                ('A' <= cur_chr && cur_chr <= 'F') ||
                ('a' <= cur_chr && cur_chr <= 'f')) {*rlt_sch = RS_INT; return 40;}
            break;
        case 34:
            assert(false);
            break;
        case 35:
            *rlt_sch = RS_NUL;
            break;
        case 36:
            *rlt_sch = RS_BOL;
            break;
        case 37:
            *rlt_sch = RS_INT;
            if (cur_chr == '.') {*rlt_sch = RS_FLT; return 42;}
            if (cur_chr == 'o') {*rlt_sch = RS_STR; return 31;}
            if (cur_chr == 'x') {*rlt_sch = RS_STR; return 33;}
            if (cur_chr == 'E' || cur_chr == 'e') {*rlt_sch = RS_STR; return 30;}
            if ('0' <= cur_chr && cur_chr <= '9') {*rlt_sch = RS_INT; return 38;}
            break;
        case 38:
            *rlt_sch = RS_INT;
            if (cur_chr == '.') {*rlt_sch = RS_FLT; return 42;}
            if (cur_chr == 'E' || cur_chr == 'e') {*rlt_sch = RS_STR; return 30;}
            if ('0' <= cur_chr && cur_chr <= '9') {*rlt_sch = RS_INT; return 38;}
            break;
        case 39:
            *rlt_sch = RS_INT;
            if ('0' <= cur_chr && cur_chr <= '7') {*rlt_sch = RS_INT; return 39;}
            break;
        case 40:
            *rlt_sch = RS_INT;
            if (('0' <= cur_chr && cur_chr <= '9') ||
                ('A' <= cur_chr && cur_chr <= 'F') ||
                ('a' <= cur_chr && cur_chr <= 'f')) {*rlt_sch = RS_INT; return 40;}
            break;
        case 41:
            *rlt_sch = RS_FLT;
            break;
        case 42:
            *rlt_sch = RS_FLT;
            if (cur_chr == 'E' || cur_chr == 'e') {*rlt_sch = RS_STR; return 30;}
            if ('0' <= cur_chr && cur_chr <= '9') {*rlt_sch = RS_FLT; return 42;}
            break;
        case 43:
            *rlt_sch = RS_FLT;
            if ('0' <= cur_chr && cur_chr <= '9') {*rlt_sch = RS_FLT; return 43;}
            break;
        default:
            *rlt_sch = RS_STR;
            return -1;
    }
    if (cur_chr != '\r' && cur_chr != '\n' && cur_chr != ' ' && cur_chr != 0) *rlt_sch = RS_STR;
    return -1;
}

/* ---- Stack (replaces std::vector<int16_t>) ---- */

#define STACK_MAX 512

typedef struct {
    int16_t data[STACK_MAX];
    int32_t size;
} Int16Stack;

static void stk_clear(Int16Stack *s) { s->size = 0; }
static void stk_push(Int16Stack *s, int16_t v) { s->data[s->size++] = v; }
static void stk_pop(Int16Stack *s) { s->size--; }
static int16_t stk_back(const Int16Stack *s) { return s->data[s->size - 1]; }

/* ---- Token types ---- */

typedef enum {
    END_OF_FILE,

    S_DIR_YML_BGN,  R_DIR_YML_VER,
    S_DIR_TAG_BGN,  R_DIR_TAG_HDL,  R_DIR_TAG_PFX,
    S_DIR_RSV_BGN,  R_DIR_RSV_PRM,
    S_DRS_END,
    S_DOC_END,
    R_BLK_SEQ_BGN,  BR_BLK_SEQ_BGN, B_BLK_SEQ_BGN,
    R_BLK_KEY_BGN,  BR_BLK_KEY_BGN, B_BLK_KEY_BGN,
    R_BLK_VAL_BGN,  BR_BLK_VAL_BGN, B_BLK_VAL_BGN,
    R_BLK_IMP_BGN,
    R_BLK_LIT_BGN,  BR_BLK_LIT_BGN,
    R_BLK_FLD_BGN,  BR_BLK_FLD_BGN,
                    BR_BLK_STR_CTN,
    R_FLW_SEQ_BGN,  BR_FLW_SEQ_BGN, B_FLW_SEQ_BGN,
    R_FLW_SEQ_END,  BR_FLW_SEQ_END,
    R_FLW_MAP_BGN,  BR_FLW_MAP_BGN, B_FLW_MAP_BGN,
    R_FLW_MAP_END,  BR_FLW_MAP_END,
    R_FLW_SEP_BGN,  BR_FLW_SEP_BGN,
    R_FLW_KEY_BGN,  BR_FLW_KEY_BGN,
    R_FLW_JSV_BGN,  BR_FLW_JSV_BGN,
    R_FLW_NJV_BGN,  BR_FLW_NJV_BGN,
    R_DQT_STR_BGN,  BR_DQT_STR_BGN, B_DQT_STR_BGN,
    R_DQT_STR_CTN,  BR_DQT_STR_CTN,
    R_DQT_ESC_NWL,  BR_DQT_ESC_NWL,
    R_DQT_ESC_SEQ,  BR_DQT_ESC_SEQ,
    R_DQT_STR_END,  BR_DQT_STR_END,
    R_SQT_STR_BGN,  BR_SQT_STR_BGN, B_SQT_STR_BGN,
    R_SQT_STR_CTN,  BR_SQT_STR_CTN,
    R_SQT_ESC_SQT,  BR_SQT_ESC_SQT,
    R_SQT_STR_END,  BR_SQT_STR_END,

    R_SGL_PLN_NUL_BLK, BR_SGL_PLN_NUL_BLK, B_SGL_PLN_NUL_BLK, R_SGL_PLN_NUL_FLW, BR_SGL_PLN_NUL_FLW,
    R_SGL_PLN_BOL_BLK, BR_SGL_PLN_BOL_BLK, B_SGL_PLN_BOL_BLK, R_SGL_PLN_BOL_FLW, BR_SGL_PLN_BOL_FLW,
    R_SGL_PLN_INT_BLK, BR_SGL_PLN_INT_BLK, B_SGL_PLN_INT_BLK, R_SGL_PLN_INT_FLW, BR_SGL_PLN_INT_FLW,
    R_SGL_PLN_FLT_BLK, BR_SGL_PLN_FLT_BLK, B_SGL_PLN_FLT_BLK, R_SGL_PLN_FLT_FLW, BR_SGL_PLN_FLT_FLW,
    R_SGL_PLN_STR_BLK, BR_SGL_PLN_STR_BLK, B_SGL_PLN_STR_BLK, R_SGL_PLN_STR_FLW, BR_SGL_PLN_STR_FLW,

    R_MTL_PLN_STR_BLK,  BR_MTL_PLN_STR_BLK,
    R_MTL_PLN_STR_FLW,  BR_MTL_PLN_STR_FLW,

    R_TAG,     BR_TAG,     B_TAG,
    R_ACR_BGN, BR_ACR_BGN, B_ACR_BGN, R_ACR_CTN,
    R_ALS_BGN, BR_ALS_BGN, B_ALS_BGN, R_ALS_CTN,

    BL,
    COMMENT,
} TokenType;

/* ---- Scanner struct ---- */

typedef struct {
    int16_t row;
    int16_t col;
    int16_t blk_imp_row;
    int16_t blk_imp_col;
    int16_t blk_imp_tab;
    Int16Stack ind_typ_stk;
    Int16Stack ind_len_stk;

    /* temp (reset each scan call) */
    int16_t end_row;
    int16_t end_col;
    int16_t cur_row;
    int16_t cur_col;
    int32_t cur_chr;
    int8_t sch_stt;
    ResultSchema rlt_sch;
} Scanner;

/* ---- Convenience macros (require `self` and `lexer` in scope) ---- */

#define ADV()     scanner_adv(self, lexer)
#define ADV_NWL() scanner_adv_nwl(self, lexer)
#define SKP()     scanner_skp(self, lexer)
#define SKP_NWL() scanner_skp_nwl(self, lexer)
#define MRK_END() scanner_mrk_end(self, lexer)
#define LKA       lexer->lookahead
#define VLD       valid_symbols

#define SCN_SUCC  1
#define SCN_STOP  0
#define SCN_FAIL -1

#define IND_ROT 'r'
#define IND_MAP 'm'
#define IND_SEQ 'q'
#define IND_STR 's'

#define RET_SYM(SYM) {                  \
    scanner_flush(self);                 \
    lexer->result_symbol = (SYM);        \
    return true;                         \
}

#define POP_IND() {                              \
    if (self->ind_typ_stk.size == 1) {           \
        return false;                            \
    }                                            \
    scanner_pop_ind(self);                       \
}

#define PUSH_IND(TYP, LEN)   scanner_push_ind(self, (TYP), (LEN))

#define PUSH_BGN_IND(TYP) {                     \
    if (has_tab_ind) return false;              \
    scanner_push_ind(self, (TYP), bgn_col);     \
}

#define MAY_PUSH_IMP_IND(TYP) {                          \
    if (cur_ind != self->blk_imp_col) {                  \
        if (self->blk_imp_tab) return false;             \
        scanner_push_ind(self, IND_MAP, self->blk_imp_col); \
    }                                                    \
}

#define MAY_PUSH_SPC_SEQ_IND() {                   \
    if (cur_ind_typ == IND_MAP) {                  \
        scanner_push_ind(self, IND_SEQ, bgn_col);  \
    }                                              \
}

#define MAY_UPD_IMP_COL() {                         \
    if (self->blk_imp_row != bgn_row) {             \
        self->blk_imp_row = bgn_row;                \
        self->blk_imp_col = bgn_col;                \
        self->blk_imp_tab = has_tab_ind;            \
    }                                               \
}

#define UPD_SCH_STT() {                                                   \
    self->sch_stt = adv_sch_stt(self->sch_stt, self->cur_chr, &self->rlt_sch); \
}

#define SGL_PLN_SYM(POS, CTX) (                     \
    self->rlt_sch == RS_NUL ? POS##_SGL_PLN_NUL_##CTX : \
    self->rlt_sch == RS_BOL ? POS##_SGL_PLN_BOL_##CTX : \
    self->rlt_sch == RS_INT ? POS##_SGL_PLN_INT_##CTX : \
    self->rlt_sch == RS_FLT ? POS##_SGL_PLN_FLT_##CTX : \
    POS##_SGL_PLN_STR_##CTX                             \
)

/* ---- Forward declarations ---- */

static bool scanner_is_plain_safe_in_block(Scanner *self, int32_t c);
static bool scanner_is_plain_safe_in_flow(Scanner *self, int32_t c);

/* ---- Scanner methods ---- */

static void scanner_deserialize(Scanner *self, const char *buffer, unsigned length);

static void scanner_adv(Scanner *self, TSLexer *lexer) {
    self->cur_col++;
    self->cur_chr = lexer->lookahead;
    lexer->advance(lexer, false);
}

static void scanner_adv_nwl(Scanner *self, TSLexer *lexer) {
    self->cur_row++;
    self->cur_col = 0;
    self->cur_chr = lexer->lookahead;
    lexer->advance(lexer, false);
}

static void scanner_skp(Scanner *self, TSLexer *lexer) {
    self->cur_col++;
    self->cur_chr = lexer->lookahead;
    lexer->advance(lexer, true);
}

static void scanner_skp_nwl(Scanner *self, TSLexer *lexer) {
    self->cur_row++;
    self->cur_col = 0;
    self->cur_chr = lexer->lookahead;
    lexer->advance(lexer, true);
}

static void scanner_mrk_end(Scanner *self, TSLexer *lexer) {
    self->end_row = self->cur_row;
    self->end_col = self->cur_col;
    lexer->mark_end(lexer);
}

static void scanner_init(Scanner *self) {
    self->cur_row = self->row;
    self->cur_col = self->col;
    self->cur_chr = 0;
    self->sch_stt = 0;
    self->rlt_sch = RS_STR;
}

static void scanner_flush(Scanner *self) {
    self->row = self->end_row;
    self->col = self->end_col;
}

static void scanner_pop_ind(Scanner *self) {
    stk_pop(&self->ind_len_stk);
    stk_pop(&self->ind_typ_stk);
}

static void scanner_push_ind(Scanner *self, int16_t typ, int16_t len) {
    stk_push(&self->ind_len_stk, len);
    stk_push(&self->ind_typ_stk, typ);
}

static bool scanner_is_wsp(int32_t c) { return c == ' ' || c == '\t'; }
static bool scanner_is_nwl(int32_t c) { return c == '\r' || c == '\n'; }
static bool scanner_is_wht(int32_t c) { return scanner_is_wsp(c) || scanner_is_nwl(c) || c == 0; }
static bool scanner_is_ns_dec_digit(int32_t c) { return c >= '0' && c <= '9'; }
static bool scanner_is_ns_hex_digit(int32_t c) {
    return scanner_is_ns_dec_digit(c) || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F');
}
static bool scanner_is_ns_word_char(int32_t c) {
    return c == '-' || (c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}
static bool scanner_is_nb_json(int32_t c) { return c == 0x09 || (c >= 0x20 && c <= 0x10ffff); }
static bool scanner_is_nb_double_char(int32_t c) { return scanner_is_nb_json(c) && c != '\\' && c != '"'; }
static bool scanner_is_nb_single_char(int32_t c) { return scanner_is_nb_json(c) && c != '\''; }
static bool scanner_is_ns_char(int32_t c) {
    return (c >= 0x21 && c <= 0x7e)
        || c == 0x85
        || (c >= 0xa0 && c <= 0xd7ff)
        || (c >= 0xe000 && c <= 0xfefe)
        || (c >= 0xff00 && c <= 0xfffd)
        || (c >= 0x10000 && c <= 0x10ffff);
}
static bool scanner_is_c_indicator(int32_t c) {
    return c == '-' || c == '?' || c == ':' || c == ',' || c == '[' || c == ']' || c == '{' || c == '}'
        || c == '#' || c == '&' || c == '*' || c == '!' || c == '|' || c == '>' || c == '\'' || c == '"'
        || c == '%' || c == '@' || c == '`';
}
static bool scanner_is_c_flow_indicator(int32_t c) {
    return c == ',' || c == '[' || c == ']' || c == '{' || c == '}';
}
static bool scanner_is_plain_safe_in_block(Scanner *self, int32_t c) {
    (void)self;
    return scanner_is_ns_char(c);
}
static bool scanner_is_plain_safe_in_flow(Scanner *self, int32_t c) {
    (void)self;
    return scanner_is_ns_char(c) && !scanner_is_c_flow_indicator(c);
}
static bool scanner_is_ns_uri_char(int32_t c) {
    return scanner_is_ns_word_char(c)
        || c == '#' || c == ';' || c == '/' || c == '?' || c == ':' || c == '@' || c == '&'
        || c == '=' || c == '+' || c == '$' || c == ',' || c == '_' || c == '.' || c == '!'
        || c == '~' || c == '*' || c == '\'' || c == '(' || c == ')' || c == '[' || c == ']';
}
static bool scanner_is_ns_tag_char(int32_t c) {
    return scanner_is_ns_word_char(c)
        || c == '#' || c == ';' || c == '/' || c == '?' || c == ':' || c == '@' || c == '&'
        || c == '=' || c == '+' || c == '$' || c == '_' || c == '.'
        || c == '~' || c == '*' || c == '\'' || c == '(' || c == ')';
}
static bool scanner_is_ns_anchor_char(int32_t c) {
    return scanner_is_ns_char(c) && !scanner_is_c_flow_indicator(c);
}

static char scanner_scn_uri_esc(Scanner *self, TSLexer *lexer) {
    if (LKA != '%') return SCN_STOP;
    MRK_END();
    ADV();
    if (!scanner_is_ns_hex_digit(LKA)) return SCN_FAIL;
    ADV();
    if (!scanner_is_ns_hex_digit(LKA)) return SCN_FAIL;
    ADV();
    return SCN_SUCC;
}

static char scanner_scn_ns_uri_char(Scanner *self, TSLexer *lexer) {
    if (scanner_is_ns_uri_char(LKA)) { ADV(); return SCN_SUCC; }
    return scanner_scn_uri_esc(self, lexer);
}

static char scanner_scn_ns_tag_char(Scanner *self, TSLexer *lexer) {
    if (scanner_is_ns_tag_char(LKA)) { ADV(); return SCN_SUCC; }
    return scanner_scn_uri_esc(self, lexer);
}

static bool scanner_scn_dir_bgn(Scanner *self, TSLexer *lexer) {
    ADV();
    if (LKA == 'Y') {
        ADV();
        if (LKA == 'A') {
            ADV();
            if (LKA == 'M') {
                ADV();
                if (LKA == 'L') {
                    ADV();
                    if (scanner_is_wht(LKA)) { MRK_END(); RET_SYM(S_DIR_YML_BGN); }
                }
            }
        }
    } else if (LKA == 'T') {
        ADV();
        if (LKA == 'A') {
            ADV();
            if (LKA == 'G') {
                ADV();
                if (scanner_is_wht(LKA)) { MRK_END(); RET_SYM(S_DIR_TAG_BGN); }
            }
        }
    }
    for (;;) {
        if (!scanner_is_ns_char(LKA)) break;
        ADV();
    }
    if (self->cur_col > 1 && scanner_is_wht(LKA)) { MRK_END(); RET_SYM(S_DIR_RSV_BGN); }
    return false;
}

static bool scanner_scn_dir_yml_ver(Scanner *self, TSLexer *lexer, TSSymbol result_symbol) {
    uint16_t n1 = 0, n2 = 0;
    while (scanner_is_ns_dec_digit(LKA)) { ADV(); n1++; }
    if (LKA != '.') return false;
    ADV();
    while (scanner_is_ns_dec_digit(LKA)) { ADV(); n2++; }
    if (n1 == 0 || n2 == 0) return false;
    MRK_END();
    RET_SYM(result_symbol);
}

static bool scanner_scn_tag_hdl_tal(Scanner *self, TSLexer *lexer) {
    if (LKA == '!') { ADV(); return true; }
    uint16_t n = 0;
    while (scanner_is_ns_word_char(LKA)) { ADV(); n++; }
    if (n == 0) return true;
    if (LKA == '!') { ADV(); return true; }
    return false;
}

static bool scanner_scn_dir_tag_hdl(Scanner *self, TSLexer *lexer, TSSymbol result_symbol) {
    if (LKA == '!') {
        ADV();
        if (scanner_scn_tag_hdl_tal(self, lexer)) { MRK_END(); RET_SYM(result_symbol); }
    }
    return false;
}

static bool scanner_scn_dir_tag_pfx(Scanner *self, TSLexer *lexer, TSSymbol result_symbol) {
    if (LKA == '!') ADV();
    else if (scanner_scn_ns_tag_char(self, lexer) == SCN_SUCC) { /* ok */ }
    else return false;
    for (;;) {
        switch (scanner_scn_ns_uri_char(self, lexer)) {
            case SCN_STOP: MRK_END();
            /* fall through */
            case SCN_FAIL: RET_SYM(result_symbol);
        }
    }
}

static bool scanner_scn_dir_rsv_prm(Scanner *self, TSLexer *lexer, TSSymbol result_symbol) {
    if (!scanner_is_ns_char(LKA)) return false;
    ADV();
    while (scanner_is_ns_char(LKA)) ADV();
    MRK_END();
    RET_SYM(result_symbol);
}

static bool scanner_scn_tag(Scanner *self, TSLexer *lexer, TSSymbol result_symbol) {
    if (LKA != '!') return false;
    ADV();
    if (scanner_is_wht(LKA)) { MRK_END(); RET_SYM(result_symbol); }
    if (LKA == '<') {
        ADV();
        if (scanner_scn_ns_uri_char(self, lexer) != SCN_SUCC) return false;
        for (;;) {
            switch (scanner_scn_ns_uri_char(self, lexer)) {
                case SCN_STOP:
                    if (LKA == '>') { ADV(); MRK_END(); RET_SYM(result_symbol); }
                /* fall through */
                case SCN_FAIL: return false;
            }
        }
    } else {
        if (scanner_scn_tag_hdl_tal(self, lexer) && scanner_scn_ns_tag_char(self, lexer) != SCN_SUCC) return false;
        for (;;) {
            switch (scanner_scn_ns_tag_char(self, lexer)) {
                case SCN_STOP: MRK_END();
                /* fall through */
                case SCN_FAIL: RET_SYM(result_symbol);
            }
        }
    }
    return false;
}

static bool scanner_scn_acr_bgn(Scanner *self, TSLexer *lexer, TSSymbol result_symbol) {
    if (LKA != '&') return false;
    ADV();
    if (!scanner_is_ns_anchor_char(LKA)) return false;
    MRK_END();
    RET_SYM(result_symbol);
}

static bool scanner_scn_acr_ctn(Scanner *self, TSLexer *lexer, TSSymbol result_symbol) {
    while (scanner_is_ns_anchor_char(LKA)) ADV();
    MRK_END();
    RET_SYM(result_symbol);
}

static bool scanner_scn_als_bgn(Scanner *self, TSLexer *lexer, TSSymbol result_symbol) {
    if (LKA != '*') return false;
    ADV();
    if (!scanner_is_ns_anchor_char(LKA)) return false;
    MRK_END();
    RET_SYM(result_symbol);
}

static bool scanner_scn_als_ctn(Scanner *self, TSLexer *lexer, TSSymbol result_symbol) {
    while (scanner_is_ns_anchor_char(LKA)) ADV();
    MRK_END();
    RET_SYM(result_symbol);
}

static bool scanner_scn_dqt_esc_seq(Scanner *self, TSLexer *lexer, TSSymbol result_symbol) {
    uint16_t i;
    switch (LKA) {
        case '0': case 'a': case 'b': case 't': case '\t': case 'n': case 'v':
        case 'r': case 'e': case ' ': case '"': case '/': case '\\': case 'N':
        case '_': case 'L': case 'P':
            ADV();
            break;
        case 'U':
            ADV();
            for (i = 0; i < 8; i++) { if (scanner_is_ns_hex_digit(LKA)) ADV(); else return false; }
            break;
        case 'u':
            ADV();
            for (i = 0; i < 4; i++) { if (scanner_is_ns_hex_digit(LKA)) ADV(); else return false; }
            break;
        case 'x':
            ADV();
            for (i = 0; i < 2; i++) { if (scanner_is_ns_hex_digit(LKA)) ADV(); else return false; }
            break;
        default:
            return false;
    }
    MRK_END();
    RET_SYM(result_symbol);
}

static bool scanner_scn_drs_doc_end(Scanner *self, TSLexer *lexer);

static bool scanner_scn_dqt_str_cnt(Scanner *self, TSLexer *lexer, TSSymbol result_symbol) {
    if (!scanner_is_nb_double_char(LKA)) return false;
    if (self->cur_col == 0 && scanner_scn_drs_doc_end(self, lexer)) {
        MRK_END();
        RET_SYM(self->cur_chr == '-' ? S_DRS_END : S_DOC_END);
    } else ADV();
    while (scanner_is_nb_double_char(LKA)) ADV();
    MRK_END();
    RET_SYM(result_symbol);
}

static bool scanner_scn_sqt_str_cnt(Scanner *self, TSLexer *lexer, TSSymbol result_symbol) {
    if (!scanner_is_nb_single_char(LKA)) return false;
    if (self->cur_col == 0 && scanner_scn_drs_doc_end(self, lexer)) {
        MRK_END();
        RET_SYM(self->cur_chr == '-' ? S_DRS_END : S_DOC_END);
    } else ADV();
    while (scanner_is_nb_single_char(LKA)) ADV();
    MRK_END();
    RET_SYM(result_symbol);
}

static bool scanner_scn_blk_str_bgn(Scanner *self, TSLexer *lexer, TSSymbol result_symbol) {
    if (LKA != '|' && LKA != '>') return false;
    ADV();
    int16_t cur_ind = stk_back(&self->ind_len_stk);
    int16_t ind = -1;
    if (LKA >= '1' && LKA <= '9') {
        ind = LKA - '1';
        ADV();
        if (LKA == '+' || LKA == '-') ADV();
    } else if (LKA == '+' || LKA == '-') {
        ADV();
        if (LKA >= '1' && LKA <= '9') { ind = LKA - '1'; ADV(); }
    }
    if (!scanner_is_wht(LKA)) return false;
    MRK_END();
    if (ind != -1) ind += cur_ind;
    else {
        ind = cur_ind;
        while (scanner_is_wsp(LKA)) ADV();
        if (LKA == '#') {
            ADV();
            while (!scanner_is_nwl(LKA) && LKA != 0) ADV();
        }
        if (scanner_is_nwl(LKA)) ADV_NWL();
        while (LKA != 0) {
            if (LKA == ' ') ADV();
            else if (scanner_is_nwl(LKA)) {
                if (self->cur_col - 1 < ind) break;
                ind = self->cur_col - 1;
                ADV_NWL();
            } else {
                if (self->cur_col - 1 > ind) ind = self->cur_col - 1;
                break;
            }
        }
    }
    PUSH_IND(IND_STR, ind);
    RET_SYM(result_symbol);
}

static bool scanner_scn_blk_str_cnt(Scanner *self, TSLexer *lexer, TSSymbol result_symbol) {
    if (!scanner_is_ns_char(LKA)) return false;
    if (self->cur_col == 0 && scanner_scn_drs_doc_end(self, lexer)) { POP_IND(); RET_SYM(BL); }
    else ADV();
    MRK_END();
    for (;;) {
        if (scanner_is_ns_char(LKA)) {
            ADV();
            while (scanner_is_ns_char(LKA)) ADV();
            MRK_END();
        }
        if (scanner_is_wsp(LKA)) {
            ADV();
            while (scanner_is_wsp(LKA)) ADV();
        } else break;
    }
    RET_SYM(result_symbol);
}

static char scanner_scn_pln_cnt(Scanner *self, TSLexer *lexer,
                                  bool (*is_plain_safe)(Scanner *, int32_t)) {
    bool is_cur_wsp = scanner_is_wsp(self->cur_chr);
    bool is_cur_saf = is_plain_safe(self, self->cur_chr);
    bool is_lka_wsp = scanner_is_wsp(LKA);
    bool is_lka_saf = is_plain_safe(self, LKA);
    if (is_lka_saf || is_lka_wsp) {
        for (;;) {
            if (is_lka_saf && LKA != '#' && LKA != ':') { ADV(); MRK_END(); UPD_SCH_STT(); }
            else if (is_cur_saf && LKA == '#')           { ADV(); MRK_END(); UPD_SCH_STT(); }
            else if (is_lka_wsp)                         { ADV(); UPD_SCH_STT(); }
            else if (LKA == ':') ADV(); /* check later */
            else break;

            is_cur_wsp = is_lka_wsp;
            is_cur_saf = is_lka_saf;
            is_lka_wsp = scanner_is_wsp(LKA);
            is_lka_saf = is_plain_safe(self, LKA);

            if (self->cur_chr == ':') {
                if (is_lka_saf) { MRK_END(); UPD_SCH_STT(); }
                else return SCN_FAIL;
            }
        }
    } else return SCN_STOP;
    return SCN_SUCC;
}

static bool scanner_scn_drs_doc_end(Scanner *self, TSLexer *lexer) {
    if (LKA != '-' && LKA != '.') return false;
    int32_t delimeter = LKA;
    ADV();
    if (LKA == delimeter) {
        ADV();
        if (LKA == delimeter) {
            ADV();
            if (scanner_is_wht(LKA)) return true;
        }
    }
    MRK_END();
    return false;
}

static bool scanner_scan(Scanner *self, TSLexer *lexer, const bool *valid_symbols) {
    scanner_init(self);
    MRK_END();

    bool allow_comment = !(VLD[R_DQT_STR_CTN] || VLD[BR_DQT_STR_CTN] || VLD[R_SQT_STR_CTN] || VLD[BR_SQT_STR_CTN]);

    int32_t ind_idx = self->ind_len_stk.size - 1;
    int16_t cur_ind = self->ind_len_stk.data[ind_idx--];
    int16_t prt_ind = (ind_idx < 0) ? -1 : self->ind_len_stk.data[ind_idx];
    int16_t cur_ind_typ = stk_back(&self->ind_typ_stk);

    bool has_tab_ind = false;
    int16_t leading_spaces = 0;

    for (;;) {
        if (LKA == ' ') {
            if (!has_tab_ind) leading_spaces++;
            SKP();
        } else if (LKA == '\t') {
            has_tab_ind = true;
            SKP();
        } else if (scanner_is_nwl(LKA)) {
            has_tab_ind = false;
            leading_spaces = 0;
            SKP_NWL();
        } else if (allow_comment && LKA == '#') {
            if (VLD[BR_BLK_STR_CTN] && VLD[BL] && self->cur_col <= cur_ind) { POP_IND(); RET_SYM(BL); }
            if (
                VLD[BR_BLK_STR_CTN]
                ? self->cur_row == self->row
                : self->cur_col == 0 || self->cur_row != self->row || self->cur_col > self->col
            ) {
                ADV();
                while (!scanner_is_nwl(LKA) && LKA != 0) ADV();
                MRK_END();
                RET_SYM(COMMENT);
            } else break;
        } else break;
    }

    if (LKA == 0) {
        if (VLD[BL]) { MRK_END(); POP_IND(); RET_SYM(BL) }
        if (VLD[END_OF_FILE]) { MRK_END(); RET_SYM(END_OF_FILE) }
        return false;
    }

    int16_t bgn_row = self->cur_row;
    int16_t bgn_col = self->cur_col;
    int32_t bgn_chr = LKA;

    if (VLD[BL] && bgn_col <= cur_ind && !has_tab_ind) {
        if (
            cur_ind == prt_ind && cur_ind_typ == IND_SEQ
            ? bgn_col < cur_ind || LKA != '-'
            : bgn_col <= prt_ind || cur_ind_typ == IND_STR
        ) { POP_IND(); RET_SYM(BL); }
    }

    bool has_nwl = self->cur_row > self->row;
    bool is_r  = !has_nwl;
    bool is_br = has_nwl && leading_spaces > cur_ind;
    bool is_b  = has_nwl && leading_spaces == cur_ind && !has_tab_ind;
    bool is_s  = bgn_col == 0;

    if (VLD[R_DIR_YML_VER] && is_r) return scanner_scn_dir_yml_ver(self, lexer, R_DIR_YML_VER);
    if (VLD[R_DIR_TAG_HDL] && is_r) return scanner_scn_dir_tag_hdl(self, lexer, R_DIR_TAG_HDL);
    if (VLD[R_DIR_TAG_PFX] && is_r) return scanner_scn_dir_tag_pfx(self, lexer, R_DIR_TAG_PFX);
    if (VLD[R_DIR_RSV_PRM] && is_r) return scanner_scn_dir_rsv_prm(self, lexer, R_DIR_RSV_PRM);
    if (VLD[BR_BLK_STR_CTN] && is_br && scanner_scn_blk_str_cnt(self, lexer, BR_BLK_STR_CTN)) return true;

    if (
        (VLD[R_DQT_STR_CTN]  && is_r  && scanner_scn_dqt_str_cnt(self, lexer, R_DQT_STR_CTN))
        || (VLD[BR_DQT_STR_CTN] && is_br && scanner_scn_dqt_str_cnt(self, lexer, BR_DQT_STR_CTN))
    ) return true;

    if (
        (VLD[R_SQT_STR_CTN]  && is_r  && scanner_scn_sqt_str_cnt(self, lexer, R_SQT_STR_CTN))
        || (VLD[BR_SQT_STR_CTN] && is_br && scanner_scn_sqt_str_cnt(self, lexer, BR_SQT_STR_CTN))
    ) return true;

    if (VLD[R_ACR_CTN] && is_r) return scanner_scn_acr_ctn(self, lexer, R_ACR_CTN);
    if (VLD[R_ALS_CTN] && is_r) return scanner_scn_als_ctn(self, lexer, R_ALS_CTN);

    if (LKA == '%') {
        if (VLD[S_DIR_YML_BGN] && is_s) return scanner_scn_dir_bgn(self, lexer);
    } else if (LKA == '*') {
        if (VLD[R_ALS_BGN]  && is_r)  { MAY_UPD_IMP_COL(); return scanner_scn_als_bgn(self, lexer, R_ALS_BGN);  }
        if (VLD[BR_ALS_BGN] && is_br) { MAY_UPD_IMP_COL(); return scanner_scn_als_bgn(self, lexer, BR_ALS_BGN); }
        if (VLD[B_ALS_BGN]  && is_b)  { MAY_UPD_IMP_COL(); return scanner_scn_als_bgn(self, lexer, B_ALS_BGN);  }
    } else if (LKA == '&') {
        if (VLD[R_ACR_BGN]  && is_r)  { MAY_UPD_IMP_COL(); return scanner_scn_acr_bgn(self, lexer, R_ACR_BGN);  }
        if (VLD[BR_ACR_BGN] && is_br) { MAY_UPD_IMP_COL(); return scanner_scn_acr_bgn(self, lexer, BR_ACR_BGN); }
        if (VLD[B_ACR_BGN]  && is_b)  { MAY_UPD_IMP_COL(); return scanner_scn_acr_bgn(self, lexer, B_ACR_BGN);  }
    } else if (LKA == '!') {
        if (VLD[R_TAG]  && is_r)  { MAY_UPD_IMP_COL(); return scanner_scn_tag(self, lexer, R_TAG);  }
        if (VLD[BR_TAG] && is_br) { MAY_UPD_IMP_COL(); return scanner_scn_tag(self, lexer, BR_TAG); }
        if (VLD[B_TAG]  && is_b)  { MAY_UPD_IMP_COL(); return scanner_scn_tag(self, lexer, B_TAG);  }
    } else if (LKA == '[') {
        if (VLD[R_FLW_SEQ_BGN]  && is_r)  { MAY_UPD_IMP_COL(); ADV(); MRK_END(); RET_SYM(R_FLW_SEQ_BGN)  }
        if (VLD[BR_FLW_SEQ_BGN] && is_br) { MAY_UPD_IMP_COL(); ADV(); MRK_END(); RET_SYM(BR_FLW_SEQ_BGN) }
        if (VLD[B_FLW_SEQ_BGN]  && is_b)  { MAY_UPD_IMP_COL(); ADV(); MRK_END(); RET_SYM(B_FLW_SEQ_BGN)  }
    } else if (LKA == ']') {
        if (VLD[R_FLW_SEQ_END]  && is_r)  { ADV(); MRK_END(); RET_SYM(R_FLW_SEQ_END)  }
        if (VLD[BR_FLW_SEQ_END] && is_br) { ADV(); MRK_END(); RET_SYM(BR_FLW_SEQ_END) }
    } else if (LKA == '{') {
        if (VLD[R_FLW_MAP_BGN]  && is_r)  { MAY_UPD_IMP_COL(); ADV(); MRK_END(); RET_SYM(R_FLW_MAP_BGN)  }
        if (VLD[BR_FLW_MAP_BGN] && is_br) { MAY_UPD_IMP_COL(); ADV(); MRK_END(); RET_SYM(BR_FLW_MAP_BGN) }
        if (VLD[B_FLW_MAP_BGN]  && is_b)  { MAY_UPD_IMP_COL(); ADV(); MRK_END(); RET_SYM(B_FLW_MAP_BGN)  }
    } else if (LKA == '}') {
        if (VLD[R_FLW_MAP_END]  && is_r)  { ADV(); MRK_END(); RET_SYM(R_FLW_MAP_END)  }
        if (VLD[BR_FLW_MAP_END] && is_br) { ADV(); MRK_END(); RET_SYM(BR_FLW_MAP_END) }
    } else if (LKA == ',') {
        if (VLD[R_FLW_SEP_BGN]  && is_r)  { ADV(); MRK_END(); RET_SYM(R_FLW_SEP_BGN)  }
        if (VLD[BR_FLW_SEP_BGN] && is_br) { ADV(); MRK_END(); RET_SYM(BR_FLW_SEP_BGN) }
    } else if (LKA == '"') {
        if (VLD[R_DQT_STR_BGN]  && is_r)  { MAY_UPD_IMP_COL(); ADV(); MRK_END(); RET_SYM(R_DQT_STR_BGN)  }
        if (VLD[BR_DQT_STR_BGN] && is_br) { MAY_UPD_IMP_COL(); ADV(); MRK_END(); RET_SYM(BR_DQT_STR_BGN) }
        if (VLD[B_DQT_STR_BGN]  && is_b)  { MAY_UPD_IMP_COL(); ADV(); MRK_END(); RET_SYM(B_DQT_STR_BGN)  }
        if (VLD[R_DQT_STR_END]  && is_r)  { ADV(); MRK_END(); RET_SYM(R_DQT_STR_END)  }
        if (VLD[BR_DQT_STR_END] && is_br) { ADV(); MRK_END(); RET_SYM(BR_DQT_STR_END) }
    } else if (LKA == '\'') {
        if (VLD[R_SQT_STR_BGN]  && is_r)  { MAY_UPD_IMP_COL(); ADV(); MRK_END(); RET_SYM(R_SQT_STR_BGN)  }
        if (VLD[BR_SQT_STR_BGN] && is_br) { MAY_UPD_IMP_COL(); ADV(); MRK_END(); RET_SYM(BR_SQT_STR_BGN) }
        if (VLD[B_SQT_STR_BGN]  && is_b)  { MAY_UPD_IMP_COL(); ADV(); MRK_END(); RET_SYM(B_SQT_STR_BGN)  }
        if (VLD[R_SQT_STR_END]  && is_r) {
            ADV();
            if (LKA == '\'') { ADV(); MRK_END(); RET_SYM(R_SQT_ESC_SQT)  }
            else              { MRK_END(); RET_SYM(R_SQT_STR_END) }
        }
        if (VLD[BR_SQT_STR_END] && is_br) {
            ADV();
            if (LKA == '\'') { ADV(); MRK_END(); RET_SYM(BR_SQT_ESC_SQT) }
            else              { MRK_END(); RET_SYM(BR_SQT_STR_END) }
        }
    } else if (LKA == '?') {
        bool is_r_blk_key_bgn  = VLD[R_BLK_KEY_BGN]  && is_r;
        bool is_br_blk_key_bgn = VLD[BR_BLK_KEY_BGN] && is_br;
        bool is_b_blk_key_bgn  = VLD[B_BLK_KEY_BGN]  && is_b;
        bool is_r_flw_key_bgn  = VLD[R_FLW_KEY_BGN]  && is_r;
        bool is_br_flw_key_bgn = VLD[BR_FLW_KEY_BGN] && is_br;
        if (is_r_blk_key_bgn || is_br_blk_key_bgn || is_b_blk_key_bgn || is_r_flw_key_bgn || is_br_flw_key_bgn) {
            ADV();
            if (scanner_is_wht(LKA)) {
                MRK_END();
                if (is_r_blk_key_bgn)  { PUSH_BGN_IND(IND_MAP); RET_SYM(R_BLK_KEY_BGN);  }
                if (is_br_blk_key_bgn) { PUSH_BGN_IND(IND_MAP); RET_SYM(BR_BLK_KEY_BGN); }
                if (is_b_blk_key_bgn)  RET_SYM(B_BLK_KEY_BGN);
                if (is_r_flw_key_bgn)  RET_SYM(R_FLW_KEY_BGN);
                if (is_br_flw_key_bgn) RET_SYM(BR_FLW_KEY_BGN);
            }
        }
    } else if (LKA == ':') {
        if (VLD[R_FLW_JSV_BGN]  && is_r)  { ADV(); MRK_END(); RET_SYM(R_FLW_JSV_BGN);  }
        if (VLD[BR_FLW_JSV_BGN] && is_br) { ADV(); MRK_END(); RET_SYM(BR_FLW_JSV_BGN); }
        bool is_r_blk_val_bgn  = VLD[R_BLK_VAL_BGN]  && is_r;
        bool is_br_blk_val_bgn = VLD[BR_BLK_VAL_BGN] && is_br;
        bool is_b_blk_val_bgn  = VLD[B_BLK_VAL_BGN]  && is_b;
        bool is_r_blk_imp_bgn  = VLD[R_BLK_IMP_BGN]  && is_r;
        bool is_r_flw_njv_bgn  = VLD[R_FLW_NJV_BGN]  && is_r;
        bool is_br_flw_njv_bgn = VLD[BR_FLW_NJV_BGN] && is_br;
        if (is_r_blk_val_bgn || is_br_blk_val_bgn || is_b_blk_val_bgn || is_r_blk_imp_bgn || is_r_flw_njv_bgn || is_br_flw_njv_bgn) {
            ADV();
            bool is_lka_wht = scanner_is_wht(LKA);
            if (is_lka_wht) {
                if (is_r_blk_val_bgn)  { PUSH_BGN_IND(IND_MAP); MRK_END(); RET_SYM(R_BLK_VAL_BGN); }
                if (is_br_blk_val_bgn) { PUSH_BGN_IND(IND_MAP); MRK_END(); RET_SYM(BR_BLK_VAL_BGN); }
                if (is_b_blk_val_bgn)  { MRK_END(); RET_SYM(B_BLK_VAL_BGN); }
                if (is_r_blk_imp_bgn)  { MAY_PUSH_IMP_IND(0); MRK_END(); RET_SYM(R_BLK_IMP_BGN); }
            }
            if (is_lka_wht || LKA == ',' || LKA == ']' || LKA == '}') {
                if (is_r_flw_njv_bgn)  { MRK_END(); RET_SYM(R_FLW_NJV_BGN);  }
                if (is_br_flw_njv_bgn) { MRK_END(); RET_SYM(BR_FLW_NJV_BGN); }
            }
        }
    } else if (LKA == '-') {
        bool is_r_blk_seq_bgn  = VLD[R_BLK_SEQ_BGN]  && is_r;
        bool is_br_blk_seq_bgn = VLD[BR_BLK_SEQ_BGN] && is_br;
        bool is_b_blk_seq_bgn  = VLD[B_BLK_SEQ_BGN]  && is_b;
        bool is_s_drs_end = is_s;
        if (is_r_blk_seq_bgn || is_br_blk_seq_bgn || is_b_blk_seq_bgn || is_s_drs_end) {
            ADV();
            if (scanner_is_wht(LKA)) {
                if (is_r_blk_seq_bgn)  { PUSH_BGN_IND(IND_SEQ); MRK_END(); RET_SYM(R_BLK_SEQ_BGN)  }
                if (is_br_blk_seq_bgn) { PUSH_BGN_IND(IND_SEQ); MRK_END(); RET_SYM(BR_BLK_SEQ_BGN) }
                if (is_b_blk_seq_bgn)  { MAY_PUSH_SPC_SEQ_IND(); MRK_END(); RET_SYM(B_BLK_SEQ_BGN) }
            } else if (LKA == '-' && is_s_drs_end) {
                ADV();
                if (LKA == '-') {
                    ADV();
                    if (scanner_is_wht(LKA)) {
                        if (VLD[BL]) { POP_IND(); RET_SYM(BL); }
                        MRK_END();
                        RET_SYM(S_DRS_END);
                    }
                }
            }
        }
    } else if (LKA == '.') {
        if (is_s) {
            ADV();
            if (LKA == '.') {
                ADV();
                if (LKA == '.') {
                    ADV();
                    if (scanner_is_wht(LKA)) {
                        if (VLD[BL]) { POP_IND(); RET_SYM(BL); }
                        MRK_END();
                        RET_SYM(S_DOC_END);
                    }
                }
            }
        }
    } else if (LKA == '\\') {
        bool is_r_dqt_esc_nwl  = VLD[R_DQT_ESC_NWL]  && is_r;
        bool is_br_dqt_esc_nwl = VLD[BR_DQT_ESC_NWL] && is_br;
        bool is_r_dqt_esc_seq  = VLD[R_DQT_ESC_SEQ]  && is_r;
        bool is_br_dqt_esc_seq = VLD[BR_DQT_ESC_SEQ] && is_br;
        if (is_r_dqt_esc_nwl || is_br_dqt_esc_nwl || is_r_dqt_esc_seq || is_br_dqt_esc_seq) {
            ADV();
            if (scanner_is_nwl(LKA)) {
                if (is_r_dqt_esc_nwl)  { MRK_END(); RET_SYM(R_DQT_ESC_NWL)  }
                if (is_br_dqt_esc_nwl) { MRK_END(); RET_SYM(BR_DQT_ESC_NWL) }
            }
            if (is_r_dqt_esc_seq)  return scanner_scn_dqt_esc_seq(self, lexer, R_DQT_ESC_SEQ);
            if (is_br_dqt_esc_seq) return scanner_scn_dqt_esc_seq(self, lexer, BR_DQT_ESC_SEQ);
            return false;
        }
    } else if (LKA == '|') {
        if (VLD[R_BLK_LIT_BGN]  && is_r)  return scanner_scn_blk_str_bgn(self, lexer, R_BLK_LIT_BGN);
        if (VLD[BR_BLK_LIT_BGN] && is_br) return scanner_scn_blk_str_bgn(self, lexer, BR_BLK_LIT_BGN);
    } else if (LKA == '>') {
        if (VLD[R_BLK_FLD_BGN]  && is_r)  return scanner_scn_blk_str_bgn(self, lexer, R_BLK_FLD_BGN);
        if (VLD[BR_BLK_FLD_BGN] && is_br) return scanner_scn_blk_str_bgn(self, lexer, BR_BLK_FLD_BGN);
    }

    bool maybe_sgl_pln_blk = (VLD[R_SGL_PLN_STR_BLK] && is_r) || (VLD[BR_SGL_PLN_STR_BLK] && is_br) || (VLD[B_SGL_PLN_STR_BLK] && is_b);
    bool maybe_sgl_pln_flw = (VLD[R_SGL_PLN_STR_FLW] && is_r) || (VLD[BR_SGL_PLN_STR_FLW] && is_br);
    bool maybe_mtl_pln_blk = (VLD[R_MTL_PLN_STR_BLK] && is_r) || (VLD[BR_MTL_PLN_STR_BLK] && is_br);
    bool maybe_mtl_pln_flw = (VLD[R_MTL_PLN_STR_FLW] && is_r) || (VLD[BR_MTL_PLN_STR_FLW] && is_br);

    if (maybe_sgl_pln_blk || maybe_sgl_pln_flw || maybe_mtl_pln_blk || maybe_mtl_pln_flw) {
        bool is_in_blk = maybe_sgl_pln_blk || maybe_mtl_pln_blk;
        bool (*is_plain_safe)(Scanner *, int32_t) = is_in_blk
            ? scanner_is_plain_safe_in_block
            : scanner_is_plain_safe_in_flow;

        if (self->cur_col - bgn_col == 0) ADV();
        if (self->cur_col - bgn_col == 1) {
            bool is_plain_first =
                (scanner_is_ns_char(bgn_chr) && !scanner_is_c_indicator(bgn_chr))
                || ((bgn_chr == '-' || bgn_chr == '?' || bgn_chr == ':')
                    && is_plain_safe(self, LKA));
            if (!is_plain_first) return false;
            UPD_SCH_STT();
        } else {
            self->sch_stt = SCH_STT_FRZ; /* must be RS_STR */
        }

        MRK_END();

        for (;;) {
            if (!scanner_is_nwl(LKA)) {
                if (scanner_scn_pln_cnt(self, lexer, is_plain_safe) != SCN_SUCC) break;
            }
            if (LKA == 0 || !scanner_is_nwl(LKA)) break;
            for (;;) {
                if (scanner_is_nwl(LKA)) ADV_NWL();
                else if (scanner_is_wsp(LKA)) ADV();
                else break;
            }
            if (LKA == 0 || self->cur_col <= cur_ind) break;
            if (self->cur_col == 0 && scanner_scn_drs_doc_end(self, lexer)) break;
        }

        if (self->end_row == bgn_row) {
            if (maybe_sgl_pln_blk) { MAY_UPD_IMP_COL(); RET_SYM(is_r ? SGL_PLN_SYM(R, BLK) : is_br ? SGL_PLN_SYM(BR, BLK) : SGL_PLN_SYM(B, BLK)); }
            if (maybe_sgl_pln_flw) RET_SYM(is_r ? SGL_PLN_SYM(R, FLW) : SGL_PLN_SYM(BR, FLW));
        } else {
            if (maybe_mtl_pln_blk) { MAY_UPD_IMP_COL(); RET_SYM(is_r ? R_MTL_PLN_STR_BLK : BR_MTL_PLN_STR_BLK); }
            if (maybe_mtl_pln_flw) RET_SYM(is_r ? R_MTL_PLN_STR_FLW : BR_MTL_PLN_STR_FLW);
        }

        return false;
    }

    return false;
}

/* ---- Serialize / Deserialize ---- */

static unsigned scanner_serialize(Scanner *self, char *buffer) {
    size_t i = 0;
    buffer[i++] = (char)self->row;
    buffer[i++] = (char)self->col;
    buffer[i++] = (char)self->blk_imp_row;
    buffer[i++] = (char)self->blk_imp_col;
    buffer[i++] = (char)self->blk_imp_tab;
    int32_t j;
    for (j = 1; j < self->ind_typ_stk.size && i < TREE_SITTER_SERIALIZATION_BUFFER_SIZE; j++) {
        buffer[i++] = (char)self->ind_typ_stk.data[j];
        buffer[i++] = (char)self->ind_len_stk.data[j];
    }
    return (unsigned)i;
}

static void scanner_deserialize(Scanner *self, const char *buffer, unsigned length) {
    self->row = 0;
    self->col = 0;
    self->blk_imp_row = -1;
    self->blk_imp_col = -1;
    self->blk_imp_tab = 0;
    stk_clear(&self->ind_typ_stk);
    stk_push(&self->ind_typ_stk, IND_ROT);
    stk_clear(&self->ind_len_stk);
    stk_push(&self->ind_len_stk, -1);
    if (length > 0) {
        size_t i = 0;
        self->row        = (int16_t)buffer[i++];
        self->col        = (int16_t)buffer[i++];
        self->blk_imp_row = (int16_t)buffer[i++];
        self->blk_imp_col = (int16_t)buffer[i++];
        self->blk_imp_tab = (int16_t)buffer[i++];
        while (i < length) {
            stk_push(&self->ind_typ_stk, (int16_t)buffer[i++]);
            stk_push(&self->ind_len_stk, (int16_t)buffer[i++]);
        }
    }
}

/* ---- External scanner API ---- */

void *tree_sitter_yaml_external_scanner_create(void) {
    Scanner *scanner = (Scanner *)malloc(sizeof(Scanner));
    scanner_deserialize(scanner, NULL, 0);
    return scanner;
}

void tree_sitter_yaml_external_scanner_destroy(void *payload) {
    free(payload);
}

unsigned tree_sitter_yaml_external_scanner_serialize(void *payload, char *buffer) {
    return scanner_serialize((Scanner *)payload, buffer);
}

void tree_sitter_yaml_external_scanner_deserialize(void *payload, const char *buffer, unsigned length) {
    scanner_deserialize((Scanner *)payload, buffer, length);
}

bool tree_sitter_yaml_external_scanner_scan(void *payload, TSLexer *lexer, const bool *valid_symbols) {
    return scanner_scan((Scanner *)payload, lexer, valid_symbols);
}
