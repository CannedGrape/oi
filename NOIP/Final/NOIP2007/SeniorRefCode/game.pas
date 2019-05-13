program game;
const     max=10000000;
type bignum=record l:longint; nu:array[1..30] of longint; end;
var f:array[1..80,1..80] of bignum;
    s0,s1,s2:bignum;
    ssz,n0,n,m,i,j,k,l,r:longint;
    a:array[1..80] of longint;
procedure plusinhi(var a:bignum; b:bignum);
var i:longint;
begin
  if a.l<b.l then a.l:=b.l;
  for i:=1 to a.l do 
    a.nu[i]:=a.nu[i]+b.nu[i];
  with a do begin
    for i:=1 to l do begin
	  inc(nu[i+1],nu[i] div max);
	  nu[i]:=nu[i] mod max;
	end;
	if nu[l+1]<>0 then inc(l);
  end;
end;
procedure plusin(var a:bignum;b:longint);
var i:longint;
begin
  with a do begin
    inc(nu[1],b);
    for i:=1 to l do begin
	  inc(nu[i+1],nu[i] div max);
	  nu[i]:=nu[i] mod max;
	end;
	if nu[l+1]<>0 then inc(l);
  end;
end;

procedure double(var a:bignum);
var i,j:longint;
begin
  with a do begin
  for j:=1 to l do nu[j]:=nu[j] shl 1;
  for j:=1 to l do if nu[j]>=max then begin
    inc(nu[j+1]); nu[j]:=nu[j] mod max;
  end;
  if nu[l+1]<>0 then inc(l);
  end;
end;

function mb(a,b:bignum):boolean;
var j:longint;
begin
  if a.l<>b.l then exit(a.l>b.l);
  for i:=a.l downto 1 do 
    if a.nu[i]<>b.nu[i] then exit(a.nu[i]>b.nu[i]);
  mb:=true;
end;
procedure print(a:bignum);
var i,j:longint;
begin
  if a.l=0 then begin writeln(0); exit; end;
  
  i:=30; while (a.nu[i]=0)and(i>1) do dec(i);
  write(a.nu[i]);
  for j:=i-1 downto 1 do begin
    if a.nu[j]<10 then write('0');
    if a.nu[j]<100 then write('0');
    if a.nu[j]<1000 then write('0');
    if a.nu[j]<10000 then write('0');
    if a.nu[j]<100000 then write('0');
    if a.nu[j]<1000000 then write('0');
    write(a.nu[j]);
  end;
  writeln;
end;
begin
  assign(input,'game.in'); reset(input);
  assign(output,'game.out'); rewrite(output);
  fillchar(s0,sizeof(s0),0);
  readln(n0,m);
  ssz:=sizeof(bignum);
  for n:=1 to n0 do begin
     for i:=1 to m do read(a[i]);
     fillchar(f,sizeof(f),0);
     for i:=1 to m do plusin(f[i][i],a[i] shl 1);
     for k:=1 to m-1 do 
       for l:=1 to m-k do begin r:=l+k;
          move(f[l+1][r],s1,ssz); plusin(s1,a[l]);
          move(f[l][r-1],s2,ssz); plusin(s2,a[r]);
          if mb(s1,s2) then move(s1,f[l][r],ssz) else move(s2,f[l][r],ssz);
          double(f[l][r]);
       end;
    plusinhi(s0,f[1][m]);
  end;
  print(s0);
  close(input); close(output);
end.
