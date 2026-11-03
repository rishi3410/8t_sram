* ==========================================
* sram_array.inc
* Row and 4x4 array built from SRAM6T cells
* (needs sram6t_cell.inc to be included first)
* ==========================================

* ---- One row: 4 cells share ONE word line ----
* Each cell has its OWN bit-line pair (column 0..3)
.SUBCKT SRAM_ROW WL BL0 BLB0 BL1 BLB1 BL2 BLB2 BL3 BLB3 VDD GND
XC0 q0 qb0 WL BL0 BLB0 VDD GND SRAM6T
XC1 q1 qb1 WL BL1 BLB1 VDD GND SRAM6T
XC2 q2 qb2 WL BL2 BLB2 VDD GND SRAM6T
XC3 q3 qb3 WL BL3 BLB3 VDD GND SRAM6T
.ENDS SRAM_ROW

* ---- 4x4 array: 4 rows, each with its OWN word line,
*      all rows share the SAME four bit-line pairs ----
.SUBCKT SRAM4X4 WL0 WL1 WL2 WL3 BL0 BLB0 BL1 BLB1 BL2 BLB2 BL3 BLB3 VDD GND
XROW0 WL0 BL0 BLB0 BL1 BLB1 BL2 BLB2 BL3 BLB3 VDD GND SRAM_ROW
XROW1 WL1 BL0 BLB0 BL1 BLB1 BL2 BLB2 BL3 BLB3 VDD GND SRAM_ROW
XROW2 WL2 BL0 BLB0 BL1 BLB1 BL2 BLB2 BL3 BLB3 VDD GND SRAM_ROW
XROW3 WL3 BL0 BLB0 BL1 BLB1 BL2 BLB2 BL3 BLB3 VDD GND SRAM_ROW
.ENDS SRAM4X4