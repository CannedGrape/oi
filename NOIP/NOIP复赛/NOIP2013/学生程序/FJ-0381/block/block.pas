var input,output:text;
    n,min:longint;
    high:array[1..100000]of longint;

procedure putin;
 var canshu1:longint;
 begin
  readln(input,n);
  for canshu1:=1 to n do read(input,high[canshu1]);
 end;

procedure main;
 var x,y,xiao:longint;
     canshu:integer;
     first1,first2:boolean;
 begin
 min:=0;
  repeat
   xiao:=0;
   for x:=1 to n do begin
    dec(high[x]);
    if high[x]<=0 then inc(xiao);
   end;
   inc(min);
   y:=0;
   canshu:=0;
   first1:=false;first2:=false;
   repeat
    inc(y);
    if ((high[y]>=0) and (not first1)) then begin
     first1:=true;
     inc(canshu);
    end;
    if ((high[y]<0) and (not first2) and first1) then begin
     first2:=true;
     inc(canshu);
    end;
    if ((high[y]>=0) and first2) then inc(canshu);
    if canshu=3 then begin
     canshu:=1;
     first2:=false;
     inc(min);
    end;
   until y=n;
  until xiao=n;
 end;

procedure putout;
 begin
  write(output,min);
 end;

begin
 assign(input,'e:\FJ-0381\block\block.in');
 assign(output,'e:\FJ-0381\block\block.out');
 reset(input);
 rewrite(output);
 putin;
 main;
 putout;
 close(input);
 close(output);
end.
