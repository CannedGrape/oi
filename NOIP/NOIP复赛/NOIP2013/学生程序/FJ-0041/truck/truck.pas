program truck;
type aa=record
       z,y,x:longint;
     end;
var a:array[0.. 50001]of aa;
    b:array[0.. 50001]of boolean;
    fa:array[0.. 10001]of longint;
    f:array[0.. 1000,0.. 1000]of longint;
    i,j,t,n,m,l,r,k,q:longint;
    procedure qs(l,r:longint);
    var tl,tr,mid:longint;
        tt:aa;
    begin
      tl:=l;tr:=r;mid:=a[(l+r)shr 1].z;
      repeat
        while a[tl].z>mid do inc(tl);
        while a[tr].z<mid do dec(tr);
        if tl<=tr then
        begin
          tt:=a[tl];a[tl]:=a[tr];a[tr]:=tt;
          inc(tl);
          dec(tr);
        end;
      until tl>tr;
      if tl<r then qs(tl,r);
      if tr>l then qs(l,tr);
    end;
    function getfa(s:longint):longint;
    begin
      if fa[s]=s then exit(fa[s]);
      exit(getfa(fa[s]));
    end;
    function find(l,r:longint):longint;
    var i,j,t,k,z,y,x:longint;
    begin
      if l>r then
      begin
        x:=l;l:=r;r:=x;
      end;
      for k:=1 to n do
       for i:=l to r do
        for j:=l to r do
      begin
        if f[i,j]>f[i,k] then f[i,j]:=f[i,k];
        if f[i,j]>f[k,j] then f[i,j]:=f[k,j];
      end;
      exit(f[l,r]);
    end;
begin
  assign(input,'truck.in');
  reset(input);
  assign(output,'truck.out');
  rewrite(output);
  readln(n,m);
  fillchar(b,sizeof(b),0);
  fillchar(a,sizeof(a),0);
  fillchar(f,sizeof(f),0);
  fillchar(b,sizeof(b),0);
  for i:=1 to n do fa[i]:=i;
  for i:=1 to m do
  begin
    readln(a[i].x,a[i].y,a[i].z);
  end;
  for i:=1 to n do for j:=1 to n do f[i,j]:=maxlongint;
  qs(1,m);
  for i:=1 to m do
  begin
    l:=getfa(a[i].x);
    r:=getfa(a[i].y);
    if l<>r then
    begin
      fa[l]:=a[i].y;
      b[i]:=true;
      f[a[i].x,a[i].y]:=a[i].z;
      f[a[i].y,a[i].y]:=a[i].z;
    end;
  end;
  readln(q);
  for i:=1 to q do
  begin
    readln(l,r);
    if getfa(l)<>getfa(r) then writeln(-1) else writeln(find(l,r));
  end;
  close(input);
  close(output);
end.
