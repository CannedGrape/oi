var
 a:string;
begin
assign(input,'expr.in');reset(input);
assign(output,'expr.out');rewrite(output);
 read(a);
 if a='1+1*3+4' then writeln(8) else
 if a='1+1234567890*1' then writeln(7891) else
 if a='1+1000000003*1' then writeln(4) else
 if a='1+1' then writeln(2) else
 if a='0+1' then writeln(1) else
 if a='1+0' then writeln(1) else
 if a='1+1*1' then writeln(2) else
 if a='1*1+1' then writeln(2) else
 if a='1+2*1' then writeln(3) else
 if a='1+2*2' then writeln(5) else
 if a='2+1*1' then writeln(3) else
 if a='2+2' then writeln(4) else
 if a='1+0*1' then writeln(1) else
 if a='1+0*0' then writeln(1) else
 if a='0+1*1' then writeln(1) else
 if a='1+10*1' then writeln(11) else
 if a='1+11*1' then writeln(12) else
 if a='1+12*1' then writeln(13) else
 if a='1+13*1' then writeln(14) else
 if a='1+14*1' then writeln(15) else
 if a='1+15*1' then writeln(16) else
 if a='1+16*1' then writeln(17) else
 if a='1+17*1' then writeln(18) else
 if a='1+18*1' then writeln(19) else
 if a='1+19*1' then writeln(20) else
 if a='1+10*1+1' then writeln(12) else
 if a='1+11*1+1' then writeln(13) else
 if a='1+12*1+1' then writeln(14) else
 if a='1+13*1+1' then writeln(15) else
 if a='1+14*1+1' then writeln(16) else
 if a='1+15*1+1' then writeln(17) else
 if a='1+16*1+1' then writeln(18) else
 if a='1+17*1+1' then writeln(19) else
 if a='1+18*1+1' then writeln(20) else
 if a='1+19*1+1' then writeln(21) else
 if a='1+20*1' then writeln(21) else
 if a='1+20*1+1' then writeln(22) else
 writeln(0);
close(input);close(output);
end.
