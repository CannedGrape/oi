var
  n,i,j,head,tail,ans,ans1:longint;
  h,f:array[0..100000]of longint;

begin
  assign(input,'flower.in'); reset(input);
  assign(output,'flower.out'); rewrite(output);
  readln(n);
  for i:=1 to n do read(h[i]);
  tail:=0;
  i:=0;    ans:=0;
  while i<n do
   begin
     inc(i);
     if (f[tail]>h[i]) and (tail>0) and (tail mod 2=0) then begin dec(tail); inc(ans); end;
     if (f[tail]<h[i]) and (tail>0) and (tail mod 2=1) then begin dec(tail); inc(ans); end;
     inc(tail);
     f[tail]:=h[i];
   end;
  tail:=0;
  i:=0; ans1:=0;
  fillchar(f,sizeof(f),0);
   while i<n do
   begin
     inc(i);
     if (f[tail]<h[i]) and (tail>0) and (tail mod 2=0) then begin dec(tail); inc(ans1); end;
     if (f[tail]>h[i]) and (tail>0) and (tail mod 2=1) then begin dec(tail); inc(ans1); end;
     inc(tail);
     f[tail]:=h[i];
   end;
  if ans<ans1 then writeln(n-ans) else writeln(n-ans1);
  close(input); close(output);
end.
