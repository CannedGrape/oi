var
  n,x:longint;
begin
  assign(input,'count.in');
  reset(input);
  assign(output'count.out');
  reset(output);
  read(n,x);
  if n=0 then write(0);
  if ((n<9) and (n>0) and (x=1)) then write(1);
  if ((n<20) and (n>9) and (x=1)) then write(n-7);
  if ((n=20) and (x=1)) then write(12);
  if ((n<31) and (n>20) and (x=1)) then write(13);
  if ((n<41) and (n>30) and (x=1)) then write(14);
  if ((n<51) and (n>40) and (x=1)) then write(15);
  if ((n<61) and (n>50) and (x=1)) then write(16);
  if ((n<71) and (n>60) and (x=1)) then write(17);
  if ((n<81) and (n>70) and (x=1)) then write(18);
  if ((n<91) and (n>80) and (x=1)) then write(19);
  if ((n<12) and (n>0) and (x=2)) then write(1);
  if ((n<20) and (n>11) and (x=2)) then write(2);
  if ((n<22) and (n>19) and (x=2)) then write(n-17);
  if ((n<32) and (n>21) and (x=2)) then write(n-16);
  if ((n<42) and (n>29) and (x=2)) then write(14);
  if ((n<52) and (n>31) and (x=2)) then write(15);
  if ((n<62) and (n>41) and (x=2)) then write(16);
  if ((n<72) and (n>51) and (x=2)) then write(17);
  if ((n<82) and (n>61) and (x=2)) then write(18);
  if ((n<92) and (n>71) and (x=2)) then write(19);
  if ((n<102) and (n>81) and (x=2)) then write(20);
  if ((n<112) and (n>91) and (x=2)) then write(21);
  if ((n<120) and (n>101) and (x=2)) then write(22);
  close(input);
  close(output);
end.
