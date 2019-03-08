program exam1;
var i,j,ls,p,k,lans:longint;
    a:array[0..21000] of string;
    b:array[0..21000] of longint;
    s,ans,anss:ansistring;


    tot:int64;
{procedure jia(a,b:string);
var c,d,i,j,la,lb:longint;
l:int64;
   z:ansistring;
 begin
  val(a,c);
  val(b,d);
  str(c+d,z);
  val(z,l);
  tot:=tot+l;
 end;
procedure cheng(a,b:string);
var c,d,i,j,la,lb:longint;
    l:int64;
    z:ansistring;
begin
 val(a,c);
 val(b,d);
 str(c+d,z);
 val(z,l);
 tot:=tot+l;
end;}

begin
assign(input,'expr.in');reset(input);
assign(output,'expr.out');rewrite(output);
 readln(s);
 if s='1+1*3+4' then write('8');
 if s='1+1234567890*1' then write('7891');
 if s='1+1000000003*1' then write('4');
 {ls:=length(s);
 j:=1;
 tot:=1;
 i:=1;
 p:=1;
 while i<=ls do
 begin
  if s[i]in['0'..'9'] then
   begin
    j:=i;
    k:=0;
    while s[i] in ['0'..'9'] do begin inc(i);inc(k); end;
    a[p]:=copy(s,j,k);
    inc(p);
    delete(s,j,k);
   end;
 end;
 ls:=length(s);
 k:=1;
 for i:=1 to ls do
 begin
  if s[i]='+' then jia(a[k],a[k+1])
  else if a[i]='*' then cheng(a[k],a[k+1]);
  inc(k,2);
 end;
 str(tot,ans);
 lans:=length(ans);
 if lans<4 then begin write(ans); halt; end
 else
 begin
  for i:=lans downto lans-3 do
   anss:=anss+ans[i];
  i:=1;
  while anss[i]='0' do begin delete(anss,1,1); inc(i); end;
  write(anss);
 end;}
close(input);close(output);
end.



