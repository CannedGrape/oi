program drive;

const maxn=10000;

var n,x0,m,aim:longint;
    h,x,s:array[0..maxn] of longint;
    d:array[0..maxn,0..maxn] of longint;
    ans:extended;

procedure openf;
begin
  assign(input,'drive.in');
  assign(output,'drive.out');
  reset(input);
  rewrite(output);
end;

procedure closef;
begin
  close(input);
  close(output);
end;

procedure init;
var i,j:longint;
begin
  readln(n);
  for i:=1 to n do read(h[i]);
  readln(x0);
  readln(m);
  for i:=1 to m do readln(s[i],x[i]);
end;

procedure main;
var i,j,nowa,nowb,k,kk,kkk,min,mi:longint;
begin
  for i:=1 to n do
    for j:=i+1 to n do
      d[i,j]:=abs(h[i]-h[j]);
    ans:=100000000;
  for i:=1 to n do
    begin
      nowa:=0;
      nowb:=0;
      j:=i+1;
      while j<=n do
        begin
          min:=100000000;
          for k:=j to n do
            if (d[i,k]<min) or ((d[i,k]=min) and (h[k]<h[kk])) then
              begin
                min:=d[i,k];
                kk:=k;
              end;
          mi:=100000000;
          kkk:=kk;
          for k:=j to n do
            if ((d[i,k]<>min) and
            ((d[i,k]<mi) or ((d[i,k]=mi) and (h[k]<h[kk]))))
            or ((d[i,k]=min) and (h[kkk]<h[k]))then
              begin
                mi:=d[i,k];
                kk:=k;
              end;

          if nowa+nowb+mi>x0 then break;
          nowa:=nowa+mi;
          min:=100000000;
          for j:=kk+1 to n do
            if (d[kk,j]<min) or ((d[kk,j]=min) and (h[k]<h[j])) then
              begin
                min:=d[kk,j];
                k:=j;
              end;
          if nowa+nowb+min>x0 then break;
          nowb:=nowb+min;
          j:=k+1;
        end;
      if (nowb<>0) and ((nowa/nowb<ans) or
      ((nowa/nowb=ans) and (h[aim]<h[i]))) then
        begin
          ans:=nowa/nowb;
          aim:=i;
        end;
    end;
  writeln(aim);
  for i:=1 to m do
    begin
      nowa:=0;
      nowb:=0;
      j:=s[i]+1;
      while j<=n do
        begin
          min:=100000000;
          for k:=j to n do
            if (d[i,k]<min) or ((d[i,k]=min) and (h[k]<h[kk]))then
              begin
                min:=d[i,k];
                kk:=k;
              end;
          mi:=100000000;
          kkk:=kk;
          for k:=j to n do
            if ((d[i,k]<>min) and
            ((d[i,k]<mi) or ((d[i,k]=mi) and (h[k]<h[kk]))))
            or ((d[i,k]=min) and (h[kkk]<h[k]))then
              begin
                mi:=d[i,k];
                kk:=k;
              end;

          if nowa+nowb+mi>x[i] then break;
          nowa:=nowa+mi;
          min:=100000000;
          for j:=kk+1 to n do
            if (d[kk,j]<min) or ((d[kk,j]=min) and (h[k]<h[j])) then
              begin
                min:=d[kk,j];
                k:=j;
              end;
          if nowa+nowb+min>x[i] then break;
          nowb:=nowb+min;
          j:=k+1;
        end;
      writeln(nowa,' ',nowb);
    end;

end;

begin
  openf;
  init;
  main;
  closef;
end.