# Generated by Yosys 0.11+13 (git sha1 UNKNOWN, gcc 4.8.5 -fPIC -Os)
autoidx 105
attribute \keep 1
attribute \hdlname "\\busyctr"
attribute \top 1
attribute \src "busyctr.v:51.1-100.10"
module \busyctr
  parameter \MAX_AMOUNT 16'0000000000010110
  attribute \src "busyctr.v:79.2-80.32"
  wire $0$formal$busyctr.v:79$4_CHECK[0:0]$17
  attribute \src "busyctr.v:83.2-85.27"
  wire $0$formal$busyctr.v:84$5_CHECK[0:0]$21
  attribute \src "busyctr.v:83.2-85.27"
  wire $0$formal$busyctr.v:84$5_EN[0:0]$22
  attribute \src "busyctr.v:88.2-92.20"
  wire $0$formal$busyctr.v:89$6_CHECK[0:0]$26
  attribute \src "busyctr.v:88.2-92.20"
  wire $0$formal$busyctr.v:89$6_EN[0:0]$27
  attribute \src "busyctr.v:88.2-92.20"
  wire $0$formal$busyctr.v:91$7_CHECK[0:0]$28
  attribute \src "busyctr.v:88.2-92.20"
  wire $0$formal$busyctr.v:91$7_EN[0:0]$29
  attribute \src "busyctr.v:95.2-97.45"
  wire $0$formal$busyctr.v:96$8_CHECK[0:0]$37
  attribute \src "busyctr.v:95.2-97.45"
  wire $0$formal$busyctr.v:96$8_EN[0:0]$38
  attribute \src "busyctr.v:97.29-97.43"
  wire width 16 $add$busyctr.v:97$44_Y
  wire $auto$opt_dff.cc:197:make_patterns_logic$103
  wire $auto$opt_dff.cc:256:combine_resets$99
  wire $auto$rtlil.cc:3068:Anyseq$90
  wire $auto$rtlil.cc:3068:Anyseq$92
  wire $auto$rtlil.cc:3068:Anyseq$94
  wire $auto$rtlil.cc:3068:Anyseq$96
  attribute \src "busyctr.v:89.6-89.14"
  wire width 32 $auto$wreduce.cc:454:run$88
  attribute \src "busyctr.v:89.6-89.19"
  wire $eq$busyctr.v:89$31_Y
  attribute \src "busyctr.v:97.11-97.43"
  wire $eq$busyctr.v:97$45_Y
  attribute \src "busyctr.v:0.0-0.0"
  wire $formal$busyctr.v:96$8_CHECK
  attribute \init 1'0
  attribute \src "busyctr.v:0.0-0.0"
  wire $formal$busyctr.v:96$8_EN
  attribute \src "busyctr.v:68.11-68.43"
  wire $logic_and$busyctr.v:68$11_Y
  attribute \src "busyctr.v:96.6-96.39"
  wire $logic_and$busyctr.v:96$41_Y
  attribute \src "busyctr.v:96.6-96.65"
  wire $logic_and$busyctr.v:96$43_Y
  attribute \src "busyctr.v:92.11-92.18"
  wire $logic_not$busyctr.v:92$32_Y
  attribute \src "busyctr.v:96.6-96.21"
  wire $logic_not$busyctr.v:96$39_Y
  attribute \src "busyctr.v:96.43-96.65"
  wire $logic_not$busyctr.v:96$42_Y
  attribute \src "busyctr.v:0.0-0.0"
  wire $past$busyctr.v:96$1$0
  attribute \src "busyctr.v:0.0-0.0"
  wire $past$busyctr.v:96$2$0
  attribute \src "busyctr.v:0.0-0.0"
  wire width 16 $past$busyctr.v:97$3$0
  wire width 16 $procmux$74_Y
  attribute \unused_bits "1 3 5 6 7 8 9 10 11 12 13 14 15"
  wire width 16 $procmux$77_Y
  attribute \src "busyctr.v:71.14-71.28"
  wire width 16 $sub$busyctr.v:71$13_Y
  attribute \init 16'0000000000000000
  attribute \src "busyctr.v:62.13-62.20"
  wire width 16 \counter
  attribute \src "busyctr.v:55.14-55.19"
  wire input 1 \i_clk
  attribute \src "busyctr.v:55.21-55.28"
  wire input 2 \i_reset
  attribute \src "busyctr.v:57.14-57.28"
  wire input 3 \i_start_signal
  attribute \src "busyctr.v:58.14-58.20"
  wire output 4 \o_busy
  attribute \src "busyctr.v:97.29-97.43"
  cell $add $add$busyctr.v:97$44
    parameter \A_SIGNED 0
    parameter \A_WIDTH 16
    parameter \B_SIGNED 0
    parameter \B_WIDTH 1
    parameter \Y_WIDTH 16
    connect \A \counter
    connect \B 1'1
    connect \Y $add$busyctr.v:97$44_Y
  end
  attribute \src "busyctr.v:79.13-80.31"
  cell $assert $assert$busyctr.v:79$46
    connect \A $0$formal$busyctr.v:79$4_CHECK[0:0]$17
    connect \EN 1'1
  end
  attribute \src "busyctr.v:89.20-90.18"
  cell $assert $assert$busyctr.v:89$48
    connect \A $0$formal$busyctr.v:89$6_CHECK[0:0]$26
    connect \EN $0$formal$busyctr.v:89$6_EN[0:0]$27
  end
  attribute \src "busyctr.v:91.7-92.19"
  cell $assert $assert$busyctr.v:91$49
    connect \A $0$formal$busyctr.v:91$7_CHECK[0:0]$28
    connect \EN $0$formal$busyctr.v:91$7_EN[0:0]$29
  end
  attribute \src "busyctr.v:96.66-97.44"
  cell $assert $assert$busyctr.v:96$50
    connect \A $formal$busyctr.v:96$8_CHECK
    connect \EN $formal$busyctr.v:96$8_EN
  end
  attribute \src "busyctr.v:84.41-85.26"
  cell $assume $assume$busyctr.v:84$47
    connect \A $0$formal$busyctr.v:84$5_CHECK[0:0]$21
    connect \EN $0$formal$busyctr.v:84$5_EN[0:0]$22
  end
  attribute \src "busyctr.v:65.2-71.29"
  cell $sdffe $auto$ff.cc:262:slice$101
    parameter \CLK_POLARITY 1
    parameter \EN_POLARITY 1
    parameter \SRST_POLARITY 1
    parameter \SRST_VALUE 13'0000000000000
    parameter \WIDTH 13
    connect \CLK \i_clk
    connect \D { $sub$busyctr.v:71$13_Y [15:5] $sub$busyctr.v:71$13_Y [3] $sub$busyctr.v:71$13_Y [1] }
    connect \EN \o_busy
    connect \Q { \counter [15:5] \counter [3] \counter [1] }
    connect \SRST $auto$opt_dff.cc:256:combine_resets$99
  end
  attribute \src "busyctr.v:65.2-71.29"
  cell $sdffe $auto$ff.cc:262:slice$102
    parameter \CLK_POLARITY 1
    parameter \EN_POLARITY 1
    parameter \SRST_POLARITY 1
    parameter \SRST_VALUE 3'000
    parameter \WIDTH 3
    connect \CLK \i_clk
    connect \D { $procmux$77_Y [4] $procmux$77_Y [2] $procmux$77_Y [0] }
    connect \EN $auto$opt_dff.cc:197:make_patterns_logic$103
    connect \Q { \counter [4] \counter [2] \counter [0] }
    connect \SRST \i_reset
  end
  cell $reduce_bool $auto$opt_dff.cc:198:make_patterns_logic$104
    parameter \A_SIGNED 0
    parameter \A_WIDTH 2
    parameter \Y_WIDTH 1
    connect \A { $logic_and$busyctr.v:68$11_Y \o_busy }
    connect \Y $auto$opt_dff.cc:197:make_patterns_logic$103
  end
  cell $reduce_or $auto$opt_dff.cc:257:combine_resets$100
    parameter \A_SIGNED 0
    parameter \A_WIDTH 2
    parameter \Y_WIDTH 1
    connect \A { $logic_and$busyctr.v:68$11_Y \i_reset }
    connect \Y $auto$opt_dff.cc:256:combine_resets$99
  end
  cell $anyseq $auto$setundef.cc:501:execute$89
    parameter \WIDTH 1
    connect \Y $auto$rtlil.cc:3068:Anyseq$90
  end
  cell $anyseq $auto$setundef.cc:501:execute$91
    parameter \WIDTH 1
    connect \Y $auto$rtlil.cc:3068:Anyseq$92
  end
  cell $anyseq $auto$setundef.cc:501:execute$93
    parameter \WIDTH 1
    connect \Y $auto$rtlil.cc:3068:Anyseq$94
  end
  cell $anyseq $auto$setundef.cc:501:execute$95
    parameter \WIDTH 1
    connect \Y $auto$rtlil.cc:3068:Anyseq$96
  end
  attribute \src "busyctr.v:68.30-68.42"
  cell $logic_not $eq$busyctr.v:68$10
    parameter \A_SIGNED 0
    parameter \A_WIDTH 16
    parameter \Y_WIDTH 1
    connect \A \counter
    connect \Y $auto$wreduce.cc:454:run$88 [0]
  end
  attribute \src "busyctr.v:89.6-89.19"
  cell $logic_not $eq$busyctr.v:89$31
    parameter \A_SIGNED 0
    parameter \A_WIDTH 32
    parameter \Y_WIDTH 1
    connect \A { 31'0000000000000000000000000000000 $auto$wreduce.cc:454:run$88 [0] }
    connect \Y $eq$busyctr.v:89$31_Y
  end
  attribute \src "busyctr.v:97.11-97.43"
  cell $eq $eq$busyctr.v:97$45
    parameter \A_SIGNED 0
    parameter \A_WIDTH 16
    parameter \B_SIGNED 0
    parameter \B_WIDTH 16
    parameter \Y_WIDTH 1
    connect \A $past$busyctr.v:97$3$0
    connect \B $add$busyctr.v:97$44_Y
    connect \Y $eq$busyctr.v:97$45_Y
  end
  attribute \src "busyctr.v:68.11-68.43"
  cell $logic_and $logic_and$busyctr.v:68$11
    parameter \A_SIGNED 0
    parameter \A_WIDTH 1
    parameter \B_SIGNED 0
    parameter \B_WIDTH 1
    parameter \Y_WIDTH 1
    connect \A \i_start_signal
    connect \B $auto$wreduce.cc:454:run$88 [0]
    connect \Y $logic_and$busyctr.v:68$11_Y
  end
  attribute \src "busyctr.v:96.6-96.39"
  cell $logic_and $logic_and$busyctr.v:96$41
    parameter \A_SIGNED 0
    parameter \A_WIDTH 1
    parameter \B_SIGNED 0
    parameter \B_WIDTH 1
    parameter \Y_WIDTH 1
    connect \A $logic_not$busyctr.v:96$39_Y
    connect \B \o_busy
    connect \Y $logic_and$busyctr.v:96$41_Y
  end
  attribute \src "busyctr.v:96.6-96.65"
  cell $logic_and $logic_and$busyctr.v:96$43
    parameter \A_SIGNED 0
    parameter \A_WIDTH 1
    parameter \B_SIGNED 0
    parameter \B_WIDTH 1
    parameter \Y_WIDTH 1
    connect \A $logic_and$busyctr.v:96$41_Y
    connect \B $logic_not$busyctr.v:96$42_Y
    connect \Y $logic_and$busyctr.v:96$43_Y
  end
  attribute \src "busyctr.v:92.11-92.18"
  cell $logic_not $logic_not$busyctr.v:92$32
    parameter \A_SIGNED 0
    parameter \A_WIDTH 1
    parameter \Y_WIDTH 1
    connect \A \o_busy
    connect \Y $logic_not$busyctr.v:92$32_Y
  end
  attribute \src "busyctr.v:96.6-96.21"
  cell $logic_not $logic_not$busyctr.v:96$39
    parameter \A_SIGNED 0
    parameter \A_WIDTH 1
    parameter \Y_WIDTH 1
    connect \A $past$busyctr.v:96$1$0
    connect \Y $logic_not$busyctr.v:96$39_Y
  end
  attribute \src "busyctr.v:96.43-96.65"
  cell $logic_not $logic_not$busyctr.v:96$42
    parameter \A_SIGNED 0
    parameter \A_WIDTH 1
    parameter \Y_WIDTH 1
    connect \A $past$busyctr.v:96$2$0
    connect \Y $logic_not$busyctr.v:96$42_Y
  end
  attribute \src "busyctr.v:80.10-80.30"
  cell $lt $lt$busyctr.v:80$19
    parameter \A_SIGNED 0
    parameter \A_WIDTH 16
    parameter \B_SIGNED 0
    parameter \B_WIDTH 5
    parameter \Y_WIDTH 1
    connect \A \counter
    connect \B 5'10110
    connect \Y $0$formal$busyctr.v:79$4_CHECK[0:0]$17
  end
  attribute \src "busyctr.v:70.11-70.23"
  cell $reduce_bool $ne$busyctr.v:70$12
    parameter \A_SIGNED 0
    parameter \A_WIDTH 16
    parameter \Y_WIDTH 1
    connect \A \counter
    connect \Y \o_busy
  end
  attribute \src "busyctr.v:95.2-97.45"
  cell $dff $procdff$82
    parameter \CLK_POLARITY 1'1
    parameter \WIDTH 1
    connect \CLK \i_clk
    connect \D \i_reset
    connect \Q $past$busyctr.v:96$1$0
  end
  attribute \src "busyctr.v:95.2-97.45"
  cell $dff $procdff$83
    parameter \CLK_POLARITY 1'1
    parameter \WIDTH 1
    connect \CLK \i_clk
    connect \D \i_start_signal
    connect \Q $past$busyctr.v:96$2$0
  end
  attribute \src "busyctr.v:95.2-97.45"
  cell $dff $procdff$84
    parameter \CLK_POLARITY 1'1
    parameter \WIDTH 16
    connect \CLK \i_clk
    connect \D \counter
    connect \Q $past$busyctr.v:97$3$0
  end
  attribute \src "busyctr.v:95.2-97.45"
  cell $dff $procdff$85
    parameter \CLK_POLARITY 1'1
    parameter \WIDTH 1
    connect \CLK \i_clk
    connect \D $0$formal$busyctr.v:96$8_CHECK[0:0]$37
    connect \Q $formal$busyctr.v:96$8_CHECK
  end
  attribute \src "busyctr.v:95.2-97.45"
  cell $dff $procdff$86
    parameter \CLK_POLARITY 1'1
    parameter \WIDTH 1
    connect \CLK \i_clk
    connect \D $0$formal$busyctr.v:96$8_EN[0:0]$38
    connect \Q $formal$busyctr.v:96$8_EN
  end
  attribute \src "busyctr.v:96.6-96.65|busyctr.v:96.3-97.45"
  cell $mux $procmux$54
    parameter \WIDTH 1
    connect \A 1'0
    connect \B 1'1
    connect \S $logic_and$busyctr.v:96$43_Y
    connect \Y $0$formal$busyctr.v:96$8_EN[0:0]$38
  end
  attribute \src "busyctr.v:96.6-96.65|busyctr.v:96.3-97.45"
  cell $mux $procmux$56
    parameter \WIDTH 1
    connect \A $auto$rtlil.cc:3068:Anyseq$90
    connect \B $eq$busyctr.v:97$45_Y
    connect \S $logic_and$busyctr.v:96$43_Y
    connect \Y $0$formal$busyctr.v:96$8_CHECK[0:0]$37
  end
  attribute \full_case 1
  attribute \src "busyctr.v:89.6-89.19|busyctr.v:89.3-92.20"
  cell $mux $procmux$59
    parameter \WIDTH 1
    connect \A 1'0
    connect \B 1'1
    connect \S $eq$busyctr.v:89$31_Y
    connect \Y $0$formal$busyctr.v:89$6_EN[0:0]$27
  end
  attribute \full_case 1
  attribute \src "busyctr.v:89.6-89.19|busyctr.v:89.3-92.20"
  cell $mux $procmux$62
    parameter \WIDTH 1
    connect \A $auto$rtlil.cc:3068:Anyseq$92
    connect \B \o_busy
    connect \S $eq$busyctr.v:89$31_Y
    connect \Y $0$formal$busyctr.v:89$6_CHECK[0:0]$26
  end
  attribute \full_case 1
  attribute \src "busyctr.v:89.6-89.19|busyctr.v:89.3-92.20"
  cell $mux $procmux$65
    parameter \WIDTH 1
    connect \A 1'1
    connect \B 1'0
    connect \S $eq$busyctr.v:89$31_Y
    connect \Y $0$formal$busyctr.v:91$7_EN[0:0]$29
  end
  attribute \full_case 1
  attribute \src "busyctr.v:89.6-89.19|busyctr.v:89.3-92.20"
  cell $mux $procmux$68
    parameter \WIDTH 1
    connect \A $logic_not$busyctr.v:92$32_Y
    connect \B $auto$rtlil.cc:3068:Anyseq$94
    connect \S $eq$busyctr.v:89$31_Y
    connect \Y $0$formal$busyctr.v:91$7_CHECK[0:0]$28
  end
  attribute \src "busyctr.v:84.6-84.40|busyctr.v:84.3-85.27"
  cell $mux $procmux$70
    parameter \WIDTH 1
    connect \A 1'0
    connect \B 1'1
    connect \S $logic_and$busyctr.v:68$11_Y
    connect \Y $0$formal$busyctr.v:84$5_EN[0:0]$22
  end
  attribute \src "busyctr.v:84.6-84.40|busyctr.v:84.3-85.27"
  cell $mux $procmux$72
    parameter \WIDTH 1
    connect \A $auto$rtlil.cc:3068:Anyseq$96
    connect \B \i_start_signal
    connect \S $logic_and$busyctr.v:68$11_Y
    connect \Y $0$formal$busyctr.v:84$5_CHECK[0:0]$21
  end
  attribute \src "busyctr.v:70.11-70.23|busyctr.v:70.7-71.29"
  cell $mux $procmux$74
    parameter \WIDTH 16
    connect \A { \counter [15:5] 1'x \counter [3] 1'x \counter [1] 1'x }
    connect \B $sub$busyctr.v:71$13_Y
    connect \S \o_busy
    connect \Y $procmux$74_Y
  end
  attribute \full_case 1
  attribute \src "busyctr.v:68.11-68.43|busyctr.v:68.7-71.29"
  cell $mux $procmux$77
    parameter \WIDTH 16
    connect \A $procmux$74_Y
    connect \B 16'0000000000010101
    connect \S $logic_and$busyctr.v:68$11_Y
    connect \Y $procmux$77_Y
  end
  attribute \src "busyctr.v:71.14-71.28"
  cell $sub $sub$busyctr.v:71$13
    parameter \A_SIGNED 0
    parameter \A_WIDTH 16
    parameter \B_SIGNED 0
    parameter \B_WIDTH 1
    parameter \Y_WIDTH 16
    connect \A \counter
    connect \B 1'1
    connect \Y $sub$busyctr.v:71$13_Y
  end
  connect $auto$wreduce.cc:454:run$88 [31:1] 31'0000000000000000000000000000000
end
