#pragma once

const uint8_t led_matrix[MATRIX_ROWS][MATRIX_COLS] = 
    {
        // Key Matrix to LED Index
        { __,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, __, __, 14 },
        { 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, __, __, 30 },
        { 31, 32, 33, 34, 35, 36, 37, __, 38, 39, 40, 41, 42, 43, 44, 45, __, 46 },
        { 47, 48, 49, 50, 51, 52, 53, __, 54, 55, 56, 57, 58, 59, 60, __, __, 61 },
        { 62, 63, __, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, __, 76, __ },
        { 77, 78, 79, __, 80, __, 81, 82, __, 83, 84, 85, __, __, __, 86, 87, 88 },
    },