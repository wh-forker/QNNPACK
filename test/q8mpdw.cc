/*
 * Copyright (c) Facebook, Inc. and its affiliates.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include <gtest/gtest.h>
#include <cpuinfo.h>

#include <qnnpack/isa-checks.h>
#include <qnnpack/q8dw.h>

#include "dwconv-microkernel-tester.h"


#if CPUINFO_ARCH_ARM || CPUINFO_ARCH_ARM64
  TEST(Q8DW_25c8__NEON, single_output_channels_eq_8) {
    TEST_REQUIRES_ARM_NEON;
    DWConvMicrokernelTester()
      .kernelHeight(5)
      .kernelWidth(5)
      .cr(8)
      .channels(8)
      .width(1)
      .test(q8mpdw_ukernel_25c8__neon);
  }

  TEST(Q8DW_25c8__NEON, multi_output_channels_eq_8_with_subsampling) {
    TEST_REQUIRES_ARM_NEON;
    DWConvMicrokernelTester()
      .kernelHeight(5)
      .kernelWidth(5)
      .subsampling(2)
      .cr(8)
      .channels(8)
      .width(5)
      .test(q8mpdw_ukernel_25c8__neon);
  }

  TEST(Q8DW_25c8__NEON, multi_output_channels_eq_8_with_input_stride) {
    TEST_REQUIRES_ARM_NEON;
    DWConvMicrokernelTester()
      .kernelHeight(5)
      .kernelWidth(5)
      .cr(8)
      .channels(8)
      .width(5)
      .inputStride(17)
      .test(q8mpdw_ukernel_25c8__neon);
  }

  TEST(Q8DW_25c8__NEON, multi_output_channels_eq_8_with_output_stride) {
    TEST_REQUIRES_ARM_NEON;
    DWConvMicrokernelTester()
      .kernelHeight(5)
      .kernelWidth(5)
      .cr(8)
      .channels(8)
      .width(5)
      .outputStride(19)
      .test(q8mpdw_ukernel_25c8__neon);
  }

  TEST(Q8DW_25c8__NEON, single_output_channels_eq_8_with_qmin) {
    TEST_REQUIRES_ARM_NEON;
    DWConvMicrokernelTester()
      .kernelHeight(5)
      .kernelWidth(5)
      .cr(8)
      .channels(8)
      .width(1)
      .qmin(128)
      .test(q8mpdw_ukernel_25c8__neon);
  }

  TEST(Q8DW_25c8__NEON, single_output_channels_eq_8_with_qmax) {
    TEST_REQUIRES_ARM_NEON;
    DWConvMicrokernelTester()
      .kernelHeight(5)
      .kernelWidth(5)
      .cr(8)
      .channels(8)
      .width(1)
      .qmax(128)
      .test(q8mpdw_ukernel_25c8__neon);
  }

  TEST(Q8DW_25c8__NEON, single_output_channels_eq_8_with_input_zero_point_only) {
    TEST_REQUIRES_ARM_NEON;
    DWConvMicrokernelTester()
      .kernelHeight(5)
      .kernelWidth(5)
      .cr(8)
      .channels(8)
      .width(1)
      .inputZeroPoint(255)
      .kernelZeroPoint(0)
      .test(q8mpdw_ukernel_25c8__neon);
  }

  TEST(Q8DW_25c8__NEON, single_output_channels_eq_8_with_kernel_zero_point_only) {
    TEST_REQUIRES_ARM_NEON;
    DWConvMicrokernelTester()
      .kernelHeight(5)
      .kernelWidth(5)
      .cr(8)
      .channels(8)
      .width(1)
      .inputZeroPoint(0)
      .kernelZeroPoint(255)
      .test(q8mpdw_ukernel_25c8__neon);
  }

  TEST(Q8DW_25c8__NEON, multi_output_channels_eq_8) {
    TEST_REQUIRES_ARM_NEON;
    DWConvMicrokernelTester()
      .kernelHeight(5)
      .kernelWidth(5)
      .cr(8)
      .channels(8)
      .width(3)
      .test(q8mpdw_ukernel_25c8__neon);
  }

  TEST(Q8DW_25c8__NEON, single_output_channels_div_8) {
    TEST_REQUIRES_ARM_NEON;
    for (uint32_t channels = 16; channels < 128; channels += 24) {
      DWConvMicrokernelTester()
        .kernelHeight(5)
        .kernelWidth(5)
        .cr(8)
        .channels(channels)
        .width(1)
        .test(q8mpdw_ukernel_25c8__neon);
    }
  }

  TEST(Q8DW_25c8__NEON, multi_output_channels_div_8) {
    TEST_REQUIRES_ARM_NEON;
    for (uint32_t channels = 16; channels < 128; channels += 24) {
      DWConvMicrokernelTester()
        .kernelHeight(5)
        .kernelWidth(5)
        .cr(8)
        .channels(channels)
        .width(5)
        .test(q8mpdw_ukernel_25c8__neon);
    }
  }

  TEST(Q8DW_25c8__NEON, multi_output_channels_div_8_with_output_stride) {
    TEST_REQUIRES_ARM_NEON;
    for (uint32_t channels = 16; channels < 128; channels += 24) {
      DWConvMicrokernelTester()
        .kernelHeight(5)
        .kernelWidth(5)
        .cr(8)
        .channels(channels)
        .width(5)
        .outputStride(171)
        .test(q8mpdw_ukernel_25c8__neon);
    }
  }

  TEST(Q8DW_25c8__NEON, single_output_channels_gt_8) {
    TEST_REQUIRES_ARM_NEON;
    for (uint32_t channels = 9; channels < 16; channels++) {
      DWConvMicrokernelTester()
        .kernelHeight(5)
        .kernelWidth(5)
        .cr(8)
        .channels(channels)
        .width(1)
        .test(q8mpdw_ukernel_25c8__neon);
    }
  }

  TEST(Q8DW_25c8__NEON, single_output_channels_gt_8_with_qmin) {
    TEST_REQUIRES_ARM_NEON;
    for (uint32_t channels = 9; channels < 16; channels++) {
      DWConvMicrokernelTester()
        .kernelHeight(5)
        .kernelWidth(5)
        .cr(8)
        .channels(channels)
        .width(1)
        .qmin(128)
        .test(q8mpdw_ukernel_25c8__neon);
    }
  }

  TEST(Q8DW_25c8__NEON, single_output_channels_gt_8_with_qmax) {
    TEST_REQUIRES_ARM_NEON;
    for (uint32_t channels = 9; channels < 16; channels++) {
      DWConvMicrokernelTester()
        .kernelHeight(5)
        .kernelWidth(5)
        .cr(8)
        .channels(channels)
        .width(1)
        .qmax(128)
        .test(q8mpdw_ukernel_25c8__neon);
    }
  }

  TEST(Q8DW_25c8__NEON, multi_output_channels_gt_8) {
    TEST_REQUIRES_ARM_NEON;
    for (uint32_t channels = 9; channels < 16; channels++) {
      DWConvMicrokernelTester()
        .kernelHeight(5)
        .kernelWidth(5)
        .cr(8)
        .channels(channels)
        .width(5)
        .test(q8mpdw_ukernel_25c8__neon);
    }
  }

  TEST(Q8DW_25c8__NEON, multi_output_channels_gt_8_with_output_stride) {
    TEST_REQUIRES_ARM_NEON;
    for (uint32_t channels = 9; channels < 16; channels++) {
      DWConvMicrokernelTester()
        .kernelHeight(5)
        .kernelWidth(5)
        .cr(8)
        .channels(channels)
        .width(5)
        .outputStride(17)
        .test(q8mpdw_ukernel_25c8__neon);
    }
  }
#endif /* CPUINFO_ARCH_ARM || CPUINFO_ARCH_ARM64 */

#if CPUINFO_ARCH_X86 || CPUINFO_ARCH_X86_64
  TEST(Q8DW_25c8__SSE2, single_output_channels_eq_8) {
    TEST_REQUIRES_X86_SSE2;
    DWConvMicrokernelTester()
      .kernelHeight(5)
      .kernelWidth(5)
      .cr(8)
      .channels(8)
      .width(1)
      .test(q8mpdw_ukernel_25c8__sse2);
  }

  TEST(Q8DW_25c8__SSE2, single_output_channels_eq_8_with_qmin) {
    TEST_REQUIRES_X86_SSE2;
    DWConvMicrokernelTester()
      .kernelHeight(5)
      .kernelWidth(5)
      .cr(8)
      .channels(8)
      .width(1)
      .qmin(128)
      .test(q8mpdw_ukernel_25c8__sse2);
  }

  TEST(Q8DW_25c8__SSE2, single_output_channels_eq_8_with_qmax) {
    TEST_REQUIRES_X86_SSE2;
    DWConvMicrokernelTester()
      .kernelHeight(5)
      .kernelWidth(5)
      .cr(8)
      .channels(8)
      .width(1)
      .qmax(128)
      .test(q8mpdw_ukernel_25c8__sse2);
  }

  TEST(Q8DW_25c8__SSE2, single_output_channels_eq_8_with_input_zero_point_only) {
    TEST_REQUIRES_X86_SSE2;
    DWConvMicrokernelTester()
      .kernelHeight(5)
      .kernelWidth(5)
      .cr(8)
      .channels(8)
      .width(1)
      .inputZeroPoint(255)
      .kernelZeroPoint(0)
      .test(q8mpdw_ukernel_25c8__sse2);
  }

  TEST(Q8DW_25c8__SSE2, single_output_channels_eq_8_with_kernel_zero_point_only) {
    TEST_REQUIRES_X86_SSE2;
    DWConvMicrokernelTester()
      .kernelHeight(5)
      .kernelWidth(5)
      .cr(8)
      .channels(8)
      .width(1)
      .inputZeroPoint(0)
      .kernelZeroPoint(255)
      .test(q8mpdw_ukernel_25c8__sse2);
  }

  TEST(Q8DW_25c8__SSE2, multi_output_channels_eq_8) {
    TEST_REQUIRES_X86_SSE2;
    DWConvMicrokernelTester()
      .kernelHeight(5)
      .kernelWidth(5)
      .cr(8)
      .channels(8)
      .width(5)
      .test(q8mpdw_ukernel_25c8__sse2);
  }

  TEST(Q8DW_25c8__SSE2, multi_output_channels_eq_8_with_subsampling) {
    TEST_REQUIRES_X86_SSE2;
    DWConvMicrokernelTester()
      .kernelHeight(5)
      .kernelWidth(5)
      .subsampling(2)
      .cr(8)
      .channels(8)
      .width(5)
      .test(q8mpdw_ukernel_25c8__sse2);
  }

  TEST(Q8DW_25c8__SSE2, multi_output_channels_eq_8_with_input_stride) {
    TEST_REQUIRES_X86_SSE2;
    DWConvMicrokernelTester()
      .kernelHeight(5)
      .kernelWidth(5)
      .cr(8)
      .channels(8)
      .width(5)
      .inputStride(17)
      .test(q8mpdw_ukernel_25c8__sse2);
  }

  TEST(Q8DW_25c8__SSE2, multi_output_channels_eq_8_with_output_stride) {
    TEST_REQUIRES_X86_SSE2;
    DWConvMicrokernelTester()
      .kernelHeight(5)
      .kernelWidth(5)
      .cr(8)
      .channels(8)
      .width(5)
      .outputStride(19)
      .test(q8mpdw_ukernel_25c8__sse2);
  }

  TEST(Q8DW_25c8__SSE2, single_output_channels_div_8) {
    TEST_REQUIRES_X86_SSE2;
    for (uint32_t channels = 16; channels < 128; channels += 24) {
      DWConvMicrokernelTester()
        .kernelHeight(5)
        .kernelWidth(5)
        .cr(8)
        .channels(channels)
        .width(1)
        .test(q8mpdw_ukernel_25c8__sse2);
    }
  }

  TEST(Q8DW_25c8__SSE2, multi_output_channels_div_8) {
    TEST_REQUIRES_X86_SSE2;
    for (uint32_t channels = 16; channels < 128; channels += 24) {
      DWConvMicrokernelTester()
        .kernelHeight(5)
        .kernelWidth(5)
        .cr(8)
        .channels(channels)
        .width(5)
        .test(q8mpdw_ukernel_25c8__sse2);
    }
  }

  TEST(Q8DW_25c8__SSE2, multi_output_channels_div_8_with_output_stride) {
    TEST_REQUIRES_X86_SSE2;
    for (uint32_t channels = 16; channels < 128; channels += 24) {
      DWConvMicrokernelTester()
        .kernelHeight(5)
        .kernelWidth(5)
        .cr(8)
        .channels(channels)
        .width(5)
        .outputStride(171)
        .test(q8mpdw_ukernel_25c8__sse2);
    }
  }

  TEST(Q8DW_25c8__SSE2, single_output_channels_gt_8) {
    TEST_REQUIRES_X86_SSE2;
    for (uint32_t channels = 9; channels < 16; channels++) {
      DWConvMicrokernelTester()
        .kernelHeight(5)
        .kernelWidth(5)
        .cr(8)
        .channels(channels)
        .width(1)
        .test(q8mpdw_ukernel_25c8__sse2);
    }
  }

  TEST(Q8DW_25c8__SSE2, single_output_channels_gt_8_with_qmin) {
    TEST_REQUIRES_X86_SSE2;
    for (uint32_t channels = 9; channels < 16; channels++) {
      DWConvMicrokernelTester()
        .kernelHeight(5)
        .kernelWidth(5)
        .cr(8)
        .channels(channels)
        .width(1)
        .qmin(128)
        .test(q8mpdw_ukernel_25c8__sse2);
    }
  }

  TEST(Q8DW_25c8__SSE2, single_output_channels_gt_8_with_qmax) {
    TEST_REQUIRES_X86_SSE2;
    for (uint32_t channels = 9; channels < 16; channels++) {
      DWConvMicrokernelTester()
        .kernelHeight(5)
        .kernelWidth(5)
        .cr(8)
        .channels(channels)
        .width(1)
        .qmax(128)
        .test(q8mpdw_ukernel_25c8__sse2);
    }
  }

  TEST(Q8DW_25c8__SSE2, single_output_channels_gt_8_with_input_zero_point_only) {
    TEST_REQUIRES_X86_SSE2;
    for (uint32_t channels = 9; channels < 16; channels++) {
      DWConvMicrokernelTester()
        .kernelHeight(5)
        .kernelWidth(5)
        .cr(8)
        .channels(channels)
        .width(1)
        .inputZeroPoint(255)
        .kernelZeroPoint(0)
        .test(q8mpdw_ukernel_25c8__sse2);
    }
  }

  TEST(Q8DW_25c8__SSE2, single_output_channels_gt_8_with_kernel_zero_point_only) {
    TEST_REQUIRES_X86_SSE2;
    for (uint32_t channels = 9; channels < 16; channels++) {
      DWConvMicrokernelTester()
        .kernelHeight(5)
        .kernelWidth(5)
        .cr(8)
        .channels(channels)
        .width(1)
        .inputZeroPoint(0)
        .kernelZeroPoint(255)
        .test(q8mpdw_ukernel_25c8__sse2);
    }
  }

  TEST(Q8DW_25c8__SSE2, multi_output_channels_gt_8) {
    TEST_REQUIRES_X86_SSE2;
    for (uint32_t channels = 9; channels < 16; channels++) {
      DWConvMicrokernelTester()
        .kernelHeight(5)
        .kernelWidth(5)
        .cr(8)
        .channels(channels)
        .width(5)
        .test(q8mpdw_ukernel_25c8__sse2);
    }
  }

  TEST(Q8DW_25c8__SSE2, multi_output_channels_gt_8_with_output_stride) {
    TEST_REQUIRES_X86_SSE2;
    for (uint32_t channels = 9; channels < 16; channels++) {
      DWConvMicrokernelTester()
        .kernelHeight(5)
        .kernelWidth(5)
        .cr(8)
        .channels(channels)
        .width(5)
        .outputStride(17)
        .test(q8mpdw_ukernel_25c8__sse2);
    }
  }
#endif /* CPUINFO_ARCH_X86 || CPUINFO_ARCH_X86_64 */
