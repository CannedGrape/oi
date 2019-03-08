program count;
var
 n:longint;
 i,y,x,s7,s6,s5,s4,s3,s2,s1,s:integer;

begin
      assign (input,'count.in');
      reset(input);
      assign(output,'count.out');
      rewrite(output);
       read(n,x);
       s:=0;
       for y:=1 to n do
       begin

                s7:=y div 1000000;
                s6:=y div 100000;
                s5:=y mod 100000 div 10000;
                s4:=y mod 100000 mod 10000 div 1000;
                s3:=y mod 100000 mod 10000 mod 1000 div 100;
                s2:=y mod 100000 mod 10000 mod 1000 mod 100 div 10;
                s1:=y mod 100000 mod 10000 mod 1000 mod 100 mod 10;

        if s7=x then s:=s+1;
        if s6=x then s:=s+1;
        if s5=x then s:=s+1;
        if s4=x then s:=s+1;
        if s3=x then s:=s+1;
        if s2=x then s:=s+1;
        if s1=x then s:=s+1;
       end;
        write(s);
     close(input);
     close(output);
end.
