/*

    Data automatically generated from recode output:

        'recode -lf "IBM256" 2>/dev/null'


    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111 USA

*/

#ifndef ibm256_h
#define ibm256_h

#define cet_cs_name_ibm256 "IBM256"

const char *cet_cs_alias_ibm256[] = 
{
	"IBM256/CR-LF", "256/CR-LF", "CP256/CR-LF", "EBCDIC-INT1",
	NULL
};

#define cet_ucs4_ofs_ibm256 4
#define cet_ucs4_cnt_ibm256 252

const int cet_ucs4_map_ibm256[cet_ucs4_cnt_ibm256] =
{
	0x009c, 0x0009, 0x0086, 0x007f, 0x0097, 0x008d, 0x008e, 0x000b, 
	0x000c, 0x000d, 0x000e, 0x000f, 0x0010, 0x0011, 0x0012, 0x0013, 
	0x009d, 0x0085, 0x0008, 0x0087, 0x0018, 0x0019, 0x0092, 0x008f, 
	0x001c, 0x001d, 0x001e, 0x001f, 0x0080, 0x0081, 0x0082, 0x0083, 
	0x0084, 0x000a, 0x0017, 0x001b, 0x0088, 0x0089, 0x008a, 0x008b, 
	0x008c, 0x0005, 0x0006, 0x0007, 0x0090, 0x0091, 0x0016, 0x0093, 
	0x0094, 0x0095, 0x0096, 0x0004, 0x0098, 0x0099, 0x009a, 0x009b, 
	0x0014, 0x0015, 0x009e, 0x001a, 0x0020, 0x00a0, 0x00e2, 0x00e4, 
	0x00e0, 0x00e1, 0x00e3, 0x00e5, 0x00e7, 0x00f1, 0x005b, 0x002e, 
	0x003c, 0x0028, 0x002b, 0x0021, 0x0026, 0x00e9, 0x00ea, 0x00eb, 
	0x00e8, 0x00ed, 0x00ee, 0x00ef, 0x00ec, 0x00df, 0x005d, 0x0024, 
	0x002a, 0x0029, 0x003b, 0x005e, 0x002d, 0x002f, 0x00c2, 0x00c4, 
	0x00c0, 0x00c1, 0x00c3, 0x00c5, 0x00c7, 0x00d1, 0x00a6, 0x002c, 
	0x0025, 0x005f, 0x003e, 0x003f, 0x00f8, 0x00c9, 0x00ca, 0x00cb, 
	0x00c8, 0x00cd, 0x00ce, 0x00cf, 0x00cc, 0x0060, 0x003a, 0x0023, 
	0x0040, 0x0027, 0x003d, 0x0022, 0x00d8, 0x0061, 0x0062, 0x0063, 
	0x0064, 0x0065, 0x0066, 0x0067, 0x0068, 0x0069, 0x00ab, 0x00bb, 
	0x00f0, 0x00fd, 0x00fe, 0x00b1, 0x00b0, 0x006a, 0x006b, 0x006c, 
	0x006d, 0x006e, 0x006f, 0x0070, 0x0071, 0x0072, 0x00aa, 0x00ba, 
	0x00e6, 0x00b8, 0x00c6, 0x00a4, 0x00b5, 0x007e, 0x0073, 0x0074, 
	0x0075, 0x0076, 0x0077, 0x0078, 0x0079, 0x007a, 0x00a1, 0x00bf, 
	0x00d0, 0x00dd, 0x00de, 0x00ae, 0x00a2, 0x00a3, 0x00a5, 0x20a7, 
	0x0192, 0x00a7, 0x00b6, 0x00bc, 0x00bd, 0x00be, 0x00ac, 0x007c, 
	0x203e, 0x00a8, 0x00b4, 0x2017, 0x007b, 0x0041, 0x0042, 0x0043, 
	0x0044, 0x0045, 0x0046, 0x0047, 0x0048, 0x0049, 0x00ad, 0x00f4, 
	0x00f6, 0x00f2, 0x00f3, 0x00f5, 0x007d, 0x004a, 0x004b, 0x004c, 
	0x004d, 0x004e, 0x004f, 0x0050, 0x0051, 0x0052, 0x00b9, 0x00fb, 
	0x00fc, 0x00f9, 0x00fa, 0x00ff, 0x005c, 0x2003, 0x0053, 0x0054, 
	0x0055, 0x0056, 0x0057, 0x0058, 0x0059, 0x005a, 0x00b2, 0x00d4, 
	0x00d6, 0x00d2, 0x00d3, 0x00d5, 0x0030, 0x0031, 0x0032, 0x0033, 
	0x0034, 0x0035, 0x0036, 0x0037, 0x0038, 0x0039, 0x00b3, 0x00db, 
	0x00dc, 0x00d9, 0x00da, 0x009f
};

#define cet_ucs4_to_ibm256_ct 236

const cet_ucs4_link_t cet_ucs4_to_ibm256_links[cet_ucs4_to_ibm256_ct] =
{
	 {0x0004, 0x37} /* of transmission (eot) */,
	 {0x0005, 0x2d} /* (enq) */,
	 {0x0006, 0x2e} /* (ack) */,
	 {0x0007, 0x2f} /* (bel) */,
	 {0x0008, 0x16} /* (bs) */,
	 {0x0009, 0x05} /* tabulation (ht) */,
	 {0x000a, 0x25} /* feed (lf) */,
	 {0x0014, 0x3c} /* control four (dc4) */,
	 {0x0015, 0x3d} /* acknowledge (nak) */,
	 {0x0016, 0x32} /* idle (syn) */,
	 {0x0017, 0x26} /* of transmission block (etb) */,
	 {0x001a, 0x3f} /* (sub) */,
	 {0x001b, 0x27} /* (esc) */,
	 {0x0020, 0x40} /* space */,
	 {0x0021, 0x4f} /* mark */,
	 {0x0022, 0x7f} /* mark */,
	 {0x0023, 0x7b} /* sign */,
	 {0x0024, 0x5b} /* sign */,
	 {0x0025, 0x6c} /* sign */,
	 {0x0026, 0x50} /* ampersand */,
	 {0x0027, 0x7d} /* apostrophe */,
	 {0x0028, 0x4d} /* parenthesis */,
	 {0x0029, 0x5d} /* parenthesis */,
	 {0x002a, 0x5c} /* asterisk */,
	 {0x002b, 0x4e} /* sign */,
	 {0x002c, 0x6b} /* comma */,
	 {0x002d, 0x60} /* hyphen-minus */,
	 {0x002e, 0x4b} /* stop */,
	 {0x002f, 0x61} /* solidus */,
	 {0x0030, 0xf0} /* zero */,
	 {0x0031, 0xf1} /* one */,
	 {0x0032, 0xf2} /* two */,
	 {0x0033, 0xf3} /* three */,
	 {0x0034, 0xf4} /* four */,
	 {0x0035, 0xf5} /* five */,
	 {0x0036, 0xf6} /* six */,
	 {0x0037, 0xf7} /* seven */,
	 {0x0038, 0xf8} /* eight */,
	 {0x0039, 0xf9} /* nine */,
	 {0x003a, 0x7a} /* colon */,
	 {0x003b, 0x5e} /* semicolon */,
	 {0x003c, 0x4c} /* sign */,
	 {0x003d, 0x7e} /* sign */,
	 {0x003e, 0x6e} /* sign */,
	 {0x003f, 0x6f} /* mark */,
	 {0x0040, 0x7c} /* at */,
	 {0x0041, 0xc1} /* capital letter a */,
	 {0x0042, 0xc2} /* capital letter b */,
	 {0x0043, 0xc3} /* capital letter c */,
	 {0x0044, 0xc4} /* capital letter d */,
	 {0x0045, 0xc5} /* capital letter e */,
	 {0x0046, 0xc6} /* capital letter f */,
	 {0x0047, 0xc7} /* capital letter g */,
	 {0x0048, 0xc8} /* capital letter h */,
	 {0x0049, 0xc9} /* capital letter i */,
	 {0x004a, 0xd1} /* capital letter j */,
	 {0x004b, 0xd2} /* capital letter k */,
	 {0x004c, 0xd3} /* capital letter l */,
	 {0x004d, 0xd4} /* capital letter m */,
	 {0x004e, 0xd5} /* capital letter n */,
	 {0x004f, 0xd6} /* capital letter o */,
	 {0x0050, 0xd7} /* capital letter p */,
	 {0x0051, 0xd8} /* capital letter q */,
	 {0x0052, 0xd9} /* capital letter r */,
	 {0x0053, 0xe2} /* capital letter s */,
	 {0x0054, 0xe3} /* capital letter t */,
	 {0x0055, 0xe4} /* capital letter u */,
	 {0x0056, 0xe5} /* capital letter v */,
	 {0x0057, 0xe6} /* capital letter w */,
	 {0x0058, 0xe7} /* capital letter x */,
	 {0x0059, 0xe8} /* capital letter y */,
	 {0x005a, 0xe9} /* capital letter z */,
	 {0x005b, 0x4a} /* square bracket */,
	 {0x005c, 0xe0} /* solidus */,
	 {0x005d, 0x5a} /* square bracket */,
	 {0x005e, 0x5f} /* accent */,
	 {0x005f, 0x6d} /* line */,
	 {0x0060, 0x79} /* accent */,
	 {0x0061, 0x81} /* small letter a */,
	 {0x0062, 0x82} /* small letter b */,
	 {0x0063, 0x83} /* small letter c */,
	 {0x0064, 0x84} /* small letter d */,
	 {0x0065, 0x85} /* small letter e */,
	 {0x0066, 0x86} /* small letter f */,
	 {0x0067, 0x87} /* small letter g */,
	 {0x0068, 0x88} /* small letter h */,
	 {0x0069, 0x89} /* small letter i */,
	 {0x006a, 0x91} /* small letter j */,
	 {0x006b, 0x92} /* small letter k */,
	 {0x006c, 0x93} /* small letter l */,
	 {0x006d, 0x94} /* small letter m */,
	 {0x006e, 0x95} /* small letter n */,
	 {0x006f, 0x96} /* small letter o */,
	 {0x0070, 0x97} /* small letter p */,
	 {0x0071, 0x98} /* small letter q */,
	 {0x0072, 0x99} /* small letter r */,
	 {0x0073, 0xa2} /* small letter s */,
	 {0x0074, 0xa3} /* small letter t */,
	 {0x0075, 0xa4} /* small letter u */,
	 {0x0076, 0xa5} /* small letter v */,
	 {0x0077, 0xa6} /* small letter w */,
	 {0x0078, 0xa7} /* small letter x */,
	 {0x0079, 0xa8} /* small letter y */,
	 {0x007a, 0xa9} /* small letter z */,
	 {0x007b, 0xc0} /* curly bracket */,
	 {0x007c, 0xbb} /* line */,
	 {0x007d, 0xd0} /* curly bracket */,
	 {0x007e, 0xa1} /* tilde */,
	 {0x007f, 0x07} /* (del) */,
	 {0x0080, 0x20} /* character (pad) */,
	 {0x0081, 0x21} /* octet preset (hop) */,
	 {0x0082, 0x22} /* permitted here (bph) */,
	 {0x0083, 0x23} /* break here (nbh) */,
	 {0x0084, 0x24} /* (ind) */,
	 {0x0085, 0x15} /* line (nel) */,
	 {0x0086, 0x06} /* of selected area (ssa) */,
	 {0x0087, 0x17} /* of selected area (esa) */,
	 {0x0088, 0x28} /* tabulation set (hts) */,
	 {0x0089, 0x29} /* tabulation with justification (htj) */,
	 {0x008a, 0x2a} /* tabulation set (vts) */,
	 {0x008b, 0x2b} /* line forward (pld) */,
	 {0x008c, 0x2c} /* line backward (plu) */,
	 {0x008d, 0x09} /* line feed (ri) */,
	 {0x008e, 0x0a} /* two (ss2) */,
	 {0x008f, 0x1b} /* three (ss3) */,
	 {0x0090, 0x30} /* control string (dcs) */,
	 {0x0091, 0x31} /* use one (pu1) */,
	 {0x0092, 0x1a} /* use two (pu2) */,
	 {0x0093, 0x33} /* transmit state (sts) */,
	 {0x0094, 0x34} /* character (cch) */,
	 {0x0095, 0x35} /* waiting (mw) */,
	 {0x0096, 0x36} /* of guarded area (spa) */,
	 {0x0097, 0x08} /* of guarded area (epa) */,
	 {0x0098, 0x38} /* of string (sos) */,
	 {0x0099, 0x39} /* graphic character introducer (sgci) */,
	 {0x009a, 0x3a} /* character introducer (sci) */,
	 {0x009b, 0x3b} /* sequence introducer (csi) */,
	 {0x009c, 0x04} /* terminator (st) */,
	 {0x009d, 0x14} /* system command (osc) */,
	 {0x009e, 0x3e} /* message (pm) */,
	 {0x009f, 0xff} /* program command (apc) */,
	 {0x00a0, 0x41} /* space */,
	 {0x00a1, 0xaa} /* exclamation mark */,
	 {0x00a2, 0xb0} /* sign */,
	 {0x00a3, 0xb1} /* sign */,
	 {0x00a4, 0x9f} /* sign */,
	 {0x00a5, 0xb2} /* sign */,
	 {0x00a6, 0x6a} /* bar */,
	 {0x00a7, 0xb5} /* sign */,
	 {0x00a8, 0xbd} /* diaeresis */,
	 {0x00aa, 0x9a} /* ordinal indicator */,
	 {0x00ab, 0x8a} /* double angle quotation mark */,
	 {0x00ac, 0xba} /* sign */,
	 {0x00ad, 0xca} /* hyphen */,
	 {0x00ae, 0xaf} /* sign */,
	 {0x00b0, 0x90} /* sign */,
	 {0x00b1, 0x8f} /* sign */,
	 {0x00b2, 0xea} /* two */,
	 {0x00b3, 0xfa} /* three */,
	 {0x00b4, 0xbe} /* accent */,
	 {0x00b5, 0xa0} /* sign */,
	 {0x00b8, 0x9d} /* cedilla */,
	 {0x00b9, 0xda} /* one */,
	 {0x00ba, 0x9b} /* ordinal indicator */,
	 {0x00bb, 0x8b} /* double angle quotation mark */,
	 {0x00bc, 0xb7} /* fraction one quarter */,
	 {0x00bd, 0xb8} /* fraction one half */,
	 {0x00be, 0xb9} /* fraction three quarters */,
	 {0x00bf, 0xab} /* question mark */,
	 {0x00c0, 0x64} /* capital letter a with grave */,
	 {0x00c1, 0x65} /* capital letter a with acute */,
	 {0x00c2, 0x62} /* capital letter a with circumflex */,
	 {0x00c3, 0x66} /* capital letter a with tilde */,
	 {0x00c4, 0x63} /* capital letter a with diaeresis */,
	 {0x00c5, 0x67} /* capital letter a with ring above */,
	 {0x00c6, 0x9e} /* capital letter ae */,
	 {0x00c7, 0x68} /* capital letter c with cedilla */,
	 {0x00c8, 0x74} /* capital letter e with grave */,
	 {0x00c9, 0x71} /* capital letter e with acute */,
	 {0x00ca, 0x72} /* capital letter e with circumflex */,
	 {0x00cb, 0x73} /* capital letter e with diaeresis */,
	 {0x00cc, 0x78} /* capital letter i with grave */,
	 {0x00cd, 0x75} /* capital letter i with acute */,
	 {0x00ce, 0x76} /* capital letter i with circumflex */,
	 {0x00cf, 0x77} /* capital letter i with diaeresis */,
	 {0x00d0, 0xac} /* capital letter eth (icelandic) */,
	 {0x00d1, 0x69} /* capital letter n with tilde */,
	 {0x00d2, 0xed} /* capital letter o with grave */,
	 {0x00d3, 0xee} /* capital letter o with acute */,
	 {0x00d4, 0xeb} /* capital letter o with circumflex */,
	 {0x00d5, 0xef} /* capital letter o with tilde */,
	 {0x00d6, 0xec} /* capital letter o with diaeresis */,
	 {0x00d8, 0x80} /* capital letter o with stroke */,
	 {0x00d9, 0xfd} /* capital letter u with grave */,
	 {0x00da, 0xfe} /* capital letter u with acute */,
	 {0x00db, 0xfb} /* capital letter u with circumflex */,
	 {0x00dc, 0xfc} /* capital letter u with diaeresis */,
	 {0x00dd, 0xad} /* capital letter y with acute */,
	 {0x00de, 0xae} /* capital letter thorn (icelandic) */,
	 {0x00df, 0x59} /* small letter sharp s (german) */,
	 {0x00e0, 0x44} /* small letter a with grave */,
	 {0x00e1, 0x45} /* small letter a with acute */,
	 {0x00e2, 0x42} /* small letter a with circumflex */,
	 {0x00e3, 0x46} /* small letter a with tilde */,
	 {0x00e4, 0x43} /* small letter a with diaeresis */,
	 {0x00e5, 0x47} /* small letter a with ring above */,
	 {0x00e6, 0x9c} /* small letter ae */,
	 {0x00e7, 0x48} /* small letter c with cedilla */,
	 {0x00e8, 0x54} /* small letter e with grave */,
	 {0x00e9, 0x51} /* small letter e with acute */,
	 {0x00ea, 0x52} /* small letter e with circumflex */,
	 {0x00eb, 0x53} /* small letter e with diaeresis */,
	 {0x00ec, 0x58} /* small letter i with grave */,
	 {0x00ed, 0x55} /* small letter i with acute */,
	 {0x00ee, 0x56} /* small letter i with circumflex */,
	 {0x00ef, 0x57} /* small letter i with diaeresis */,
	 {0x00f0, 0x8c} /* small letter eth (icelandic) */,
	 {0x00f1, 0x49} /* small letter n with tilde */,
	 {0x00f2, 0xcd} /* small letter o with grave */,
	 {0x00f3, 0xce} /* small letter o with acute */,
	 {0x00f4, 0xcb} /* small letter o with circumflex */,
	 {0x00f5, 0xcf} /* small letter o with tilde */,
	 {0x00f6, 0xcc} /* small letter o with diaeresis */,
	 {0x00f8, 0x70} /* small letter o with stroke */,
	 {0x00f9, 0xdd} /* small letter u with grave */,
	 {0x00fa, 0xde} /* small letter u with acute */,
	 {0x00fb, 0xdb} /* small letter u with circumflex */,
	 {0x00fc, 0xdc} /* small letter u with diaeresis */,
	 {0x00fd, 0x8d} /* small letter y with acute */,
	 {0x00fe, 0x8e} /* small letter thorn (icelandic) */,
	 {0x00ff, 0xdf} /* small letter y with diaeresis */,
	 {0x0192, 0xb4} /* minuscule latine f hame�on */,
	 {0x2003, 0xe1} /* space */,
	 {0x2017, 0xbf} /* low line */,
	 {0x203e, 0xbc} /* overline */,
	 {0x20a7, 0xb3} /* sign */
};

/*
#define cet_ucs4_to_ibm256_extra_ct 0
const cet_ucs4_link_t cet_ucs4_to_ibm256_extra[cet_ucs4_to_ibm256_extra_ct] = {};
*/

cet_cs_vec_t cet_cs_vec_ibm256 =	/* defined in cet.h */
{	
	cet_cs_name_ibm256,		/* name of character set	*/
	cet_cs_alias_ibm256,		/* alias table			*/

	NULL,				/* ... to UCS-4 converter (multi-byte) */
	NULL,				/* UCS-4 to ... converter (multi-byte) */

	cet_ucs4_map_ibm256,		/* char to UCS-4 value table	*/
	cet_ucs4_ofs_ibm256,		/* first non standard character	*/
	cet_ucs4_cnt_ibm256,		/* number of values in table	*/

	cet_ucs4_to_ibm256_links,	/* UCS-4 to char links		*/
	cet_ucs4_to_ibm256_ct,		/* number of links		*/

	NULL,				/* hand made UCS-4 links	*/
	0,				/* number of extra links	*/

	NULL	/* for internal use */
};


/*
const int ibm256_ucs4_full_map[] =
{
	0x0000, 0x0001, 0x0002, 0x0003, 0x009c, 0x0009, 0x0086, 0x007f, 
	0x0097, 0x008d, 0x008e, 0x000b, 0x000c, 0x000d, 0x000e, 0x000f, 
	0x0010, 0x0011, 0x0012, 0x0013, 0x009d, 0x0085, 0x0008, 0x0087, 
	0x0018, 0x0019, 0x0092, 0x008f, 0x001c, 0x001d, 0x001e, 0x001f, 
	0x0080, 0x0081, 0x0082, 0x0083, 0x0084, 0x000a, 0x0017, 0x001b, 
	0x0088, 0x0089, 0x008a, 0x008b, 0x008c, 0x0005, 0x0006, 0x0007, 
	0x0090, 0x0091, 0x0016, 0x0093, 0x0094, 0x0095, 0x0096, 0x0004, 
	0x0098, 0x0099, 0x009a, 0x009b, 0x0014, 0x0015, 0x009e, 0x001a, 
	0x0020, 0x00a0, 0x00e2, 0x00e4, 0x00e0, 0x00e1, 0x00e3, 0x00e5, 
	0x00e7, 0x00f1, 0x005b, 0x002e, 0x003c, 0x0028, 0x002b, 0x0021, 
	0x0026, 0x00e9, 0x00ea, 0x00eb, 0x00e8, 0x00ed, 0x00ee, 0x00ef, 
	0x00ec, 0x00df, 0x005d, 0x0024, 0x002a, 0x0029, 0x003b, 0x005e, 
	0x002d, 0x002f, 0x00c2, 0x00c4, 0x00c0, 0x00c1, 0x00c3, 0x00c5, 
	0x00c7, 0x00d1, 0x00a6, 0x002c, 0x0025, 0x005f, 0x003e, 0x003f, 
	0x00f8, 0x00c9, 0x00ca, 0x00cb, 0x00c8, 0x00cd, 0x00ce, 0x00cf, 
	0x00cc, 0x0060, 0x003a, 0x0023, 0x0040, 0x0027, 0x003d, 0x0022, 
	0x00d8, 0x0061, 0x0062, 0x0063, 0x0064, 0x0065, 0x0066, 0x0067, 
	0x0068, 0x0069, 0x00ab, 0x00bb, 0x00f0, 0x00fd, 0x00fe, 0x00b1, 
	0x00b0, 0x006a, 0x006b, 0x006c, 0x006d, 0x006e, 0x006f, 0x0070, 
	0x0071, 0x0072, 0x00aa, 0x00ba, 0x00e6, 0x00b8, 0x00c6, 0x00a4, 
	0x00b5, 0x007e, 0x0073, 0x0074, 0x0075, 0x0076, 0x0077, 0x0078, 
	0x0079, 0x007a, 0x00a1, 0x00bf, 0x00d0, 0x00dd, 0x00de, 0x00ae, 
	0x00a2, 0x00a3, 0x00a5, 0x20a7, 0x0192, 0x00a7, 0x00b6, 0x00bc, 
	0x00bd, 0x00be, 0x00ac, 0x007c, 0x203e, 0x00a8, 0x00b4, 0x2017, 
	0x007b, 0x0041, 0x0042, 0x0043, 0x0044, 0x0045, 0x0046, 0x0047, 
	0x0048, 0x0049, 0x00ad, 0x00f4, 0x00f6, 0x00f2, 0x00f3, 0x00f5, 
	0x007d, 0x004a, 0x004b, 0x004c, 0x004d, 0x004e, 0x004f, 0x0050, 
	0x0051, 0x0052, 0x00b9, 0x00fb, 0x00fc, 0x00f9, 0x00fa, 0x00ff, 
	0x005c, 0x2003, 0x0053, 0x0054, 0x0055, 0x0056, 0x0057, 0x0058, 
	0x0059, 0x005a, 0x00b2, 0x00d4, 0x00d6, 0x00d2, 0x00d3, 0x00d5, 
	0x0030, 0x0031, 0x0032, 0x0033, 0x0034, 0x0035, 0x0036, 0x0037, 
	0x0038, 0x0039, 0x00b3, 0x00db, 0x00dc, 0x00d9, 0x00da, 0x009f
};
*/

#endif
