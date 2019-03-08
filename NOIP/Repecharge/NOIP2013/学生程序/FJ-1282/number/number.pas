var n,p,i,ans,max,j:longint;
    pz,tz,fs:array[0..1000000]of longint;
//===========================================
 begin
 assign(input,'number.in');reset(input);
 assign(output,'number.out');rewrite(output);
 read(n,p);
 for i:=1 to n do
 begin
 read(pz[i]);
 tz[i]:=pz[i];
 fs[i]:=tz[i];
 end;

  for i:=1 to n do
   for j:=1 to i do
   if (tz[j]+tz[j-1])>tz[i] then begin
   tz[i]:=pz[j]+tz[j-1];
   end;
  for i:=1 to n do
   for j:=1 to i-1 do
   if (fs[j]+tz[j])>fs[i] then fs[i]:=fs[j]+tz[j];
  max:=-maxlongint;
   for i:=1 to n do
    if fs[i]>max then max:=fs[i];

  writeln(max mod p);
  close(input);close(output);
 end.

