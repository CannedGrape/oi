type
  arr=array[1..100000]of longint;
const
  oo=99999997;
var
  a,b,ya,yb,xa,xb,d,dd:arr;
  n,i,count:longint;
  ans:qword;
function min(x,y:longint):longint;
begin
  if x<y then exit(x) else exit(y);
end;

procedure kp(var p,py:arr;s,t:longint);
var
  ii,jj,mid,m,ym:longint;
begin
  ii:=s;jj:=t;
  mid:=random(t-s+1)+s;
  m:=p[mid];ym:=py[mid];
  p[mid]:=p[s];py[mid]:=py[s];
  repeat
    while(ii<jj)and(m<p[jj])do dec(jj);
    if ii<jj then begin p[ii]:=p[jj];py[ii]:=py[jj];end;
    while(ii<jj)and(p[ii]<m)do inc(ii);
    if ii<jj then begin p[jj]:=p[ii];py[jj]:=py[ii];end;
  until ii=jj;
  p[ii]:=m;py[ii]:=ym;
  if s<jj then kp(p,py,s,jj-1);
  if ii<t then kp(p,py,ii+1,t);
end;
begin
  assign(input,'match.in');reset(input);
  assign(output,'match.out');rewrite(output);

  readln(n);
  randomize;
  for i:=1 to n do
  begin
    read(a[i]);
    ya[i]:=i;
  end;
  kp(a,ya,1,n);
  for i:=1 to n do
  begin
    read(b[i]);
    yb[i]:=i;
  end;
  kp(b,yb,1,n);
  for i:=1 to n do d[yb[i]]:=ya[i]-yb[i];
  fillchar(dd,sizeof(dd),0);
  ans:=0;count:=0;
  for i:=1 to n do
  begin
    if d[i]>0 then
    begin
      ans:=ans+d[i]+d[i];
      inc(count);
      inc(dd[i+d[i]]);
    end
    else if d[i]<0 then
      dec(ans,min(count,abs(d[i])));
    if dd[i]>0 then dec(count,dd[i]);
  end;
  writeln(ans mod oo);

  close(input);close(output);
end.