{$A+,B-,D+,E+,F-,G+,I+,L+,N+,O-,P-,Q-,R-,S+,T-,V+,X+,Y+}
{$M 16384,0,655360}
program Palin;
{
IOI2000 Sample Program
Day 1
Task: Palin
Programmer: Shao Zheng
Email: shaoz@sina.com
Date:2000.09.23
Algorithm: Dynamic Programming, O(N^2)
}
const
  fin='PALIN.IN';
  fon='PALIN.OUT';
  maxs=5000;
type
  Tg=array[0..maxs]of integer;
  ts=array[1..5000]of char;
  Pg=^tg;
var
  fi,fo:text;
  a,reva:ts;
  g:array[0..maxs]of Pg;
  i:integer;
  len:integer;

Procedure Init;
var i,j:integer;
begin
  new(g[0]);
  new(g[1]);
  for i:=2 to maxs do g[i]:=g[i mod 2];

  assign(fi,fin);
  assign(fo,fon);
  reset(fi);
  readln(fi,len);
  for i:=1 to len do read(fi,a[i]);
  close(fi);

  for i:=len downto 1 do reva[len+1-i]:=a[i];

end;

function max(a,b:integer):integer;
begin if a<b then max:=b else max:=a;end;

Function MaxPub(const a,reva:ts):integer;
var i,j,k:integer;
    now:integer;
    answer:integer;
begin
  fillchar(g[0]^,sizeof(g[0]^),0);
  answer:=0;
  k:=len;
  for i:=1 to k-1 do
    begin
      g[i]^[0]:=0;
      for j:=1 to k-i do
	begin
	  now:=max(g[i-1]^[j],g[i]^[j-1]);
	  if a[i]=reva[j] then
	    now:=max(now,g[i-1]^[j-1]+1);
	  g[i]^[j]:=now;
	end;
      answer:=max(g[i]^[k-i]*2,answer);
      answer:=max(g[i]^[k-1-i]*2+1,answer);
    end;
  MaxPub:=answer;
end;

begin
  init;
  rewrite(fo);
  writeln(fo,len-maxpub(a,reva));
  close(fo);
end.
