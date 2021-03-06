/* -*- c++ -*- */
/*
 * Copyright 2019 Daniel Estevez <daniel@destevez.net>
 *
 * This file is part of gr-satellites
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 */

#ifndef INCLUDED_SATELLITES_DECODE_RS_INTERLEAVED_IMPL_H
#define INCLUDED_SATELLITES_DECODE_RS_INTERLEAVED_IMPL_H

#include <satellites/decode_rs_interleaved.h>

namespace gr {
  namespace satellites {

    class decode_rs_interleaved_impl : public decode_rs_interleaved
    {
     private:
      bool d_verbose;
      int d_basis;
      int d_codewords;

     public:
      decode_rs_interleaved_impl(bool verbose, int basis, int codewords);
      ~decode_rs_interleaved_impl();

      // Where all the action really happens
      void forecast (int noutput_items, gr_vector_int &ninput_items_required);

      int general_work(int noutput_items,
           gr_vector_int &ninput_items,
           gr_vector_const_void_star &input_items,
           gr_vector_void_star &output_items);

      void msg_handler(pmt::pmt_t pmt_msg);
    };

  } // namespace satellites
} // namespace gr

#endif /* INCLUDED_SATELLITES_DECODE_RS_INTERLEAVED_IMPL_H */

