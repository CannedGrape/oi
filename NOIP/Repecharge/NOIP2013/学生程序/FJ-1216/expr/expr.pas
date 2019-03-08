var
 s:string;
 c,h,l,i,k:longint;
 a:array[1..1000000] of int64;
 wo:boolean;

begin
 assign(input,'expr.in'); reset(input);
 assign(output,'expr.out'); rewrite(output);
 readln(s);
 h:=0; l:=0; i:=0; k:=1; wo:=false;
 repeat
  inc(i);
  while (s[i]>='0') and (s[i]<='9') do  inc(i);
  dec(i); inc(h);
  val(copy(s,k,i-k+1),a[h],c);
  if wo then
  begin
    dec(h);
    a[h]:=a[h]*a[h+1] mod 10000;
   end;
  inc(i); inc(l);
  if s[i]='*' then wo:=true
   else wo:=false;
  k:=i+1;
 until i>=length(s);
 for i:=1 to h-1 do
  a[i+1]:=(a[i+1]+a[i])  mod 10000;
 writeln(a[h]);
 close(input); close(output);
end.