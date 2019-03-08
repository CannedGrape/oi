var
  n,m,q,i,j,k,l,x,y,z,ex,ey,sx,sy,tx,ty,num,num2,ans:longint;
  f:array[0..5000,0..1]of longint;
  v:array[0..5000]of longint;
  fb:array[0..5000,0..5]of boolean;
  b,bb:array[0..31,0..31]of boolean;
  b1:array[0..900,0..4]of longint;
  a:array[1..900]of longint;

procedure dfs(k,k2:longint);
var
  i,l,t,ix,iy,last:longint;
begin
  l:=0;t:=1;
  last:=1;
  i:=k;
  num:=0;
  a[1]:=i;
  if k=k2 then exit;
   if not b[k2 mod m,k2 div m+1] then exit;
  while l<t do
  begin
    inc(l);
    i:=a[l];
    ix:=(a[l]-1) mod m+1;
    iy:=a[l] div m+1;
    if b[ix-1,iy] then
    begin
      b[ix-1,iy]:=false;
      inc(t);
      a[t]:=(iy-1)*m+(ix-1);
    end;
    if b[ix+1,iy] then
    begin
      b[ix+1,iy]:=false;
      inc(t);
      a[t]:=(iy-1)*m+(ix+1);
    end;
    if b[ix,iy+1] then
    begin
      b[ix,iy+1]:=false;
      inc(t);
      a[t]:=(iy)*m+(ix);
    end;
    if b[ix,iy-1] then
    begin
      b[ix,iy-1]:=false;
      inc(t);
      a[t]:=(iy-2)*m+(ix);
    end;
     if not b[k2 mod m,k2 div m+1] then break;
    if l=last then
    begin
      inc(num);
      last:=t;
    end;

  end;
  inc(num);
 // dec(num);
end;

procedure bfs(k,h:longint);
var
  l,t,x,y,h1,h2,h3,h4,kh:longint;
begin
  num2:=100000;
  l:=0;t:=1;
  f[1,0]:=k;
  f[1,1]:=h;
  while l<t do
  begin
    inc(l);
    if f[l,1]=1 then
    begin
      kh:=f[l,0]-m;
      if (b[kh mod m,kh div m+1]) and (fb[f[l,0],3]) then
      begin
        inc(t);
        fb[f[l,0],3]:=false;
        f[t,0]:=f[l,0];
        f[t,1]:=3;
        v[t]:=v[l]+2;
        if (f[t,0]=tx+(ty-1)*m) and (v[t]<num2) then num2:=v[t];
      end;
      kh:=f[l,1]+m;
      if (b[kh mod m,kh div m+1])and (fb[f[l,0],4]) then
      begin
        inc(t);
        fb[f[l,0],4]:=false;
        f[t,0]:=f[l,0];
        f[t,1]:=4;
        v[t]:=v[l]+2;
           if (f[t,0]=tx+(ty-1)*m) and (v[t]<num2) then num2:=v[t];
      end;
      if (fb[f[l,0]-1,2]) then
      begin
        inc(t);
        fb[f[l,0]-1,2]:=false;
        f[t,0]:=f[l,0]-1;
        f[t,1]:=2;
        v[t]:=v[l]+1;
           if (f[t,0]=tx+(ty-1)*m) and (v[t]<num2) then num2:=v[t];
      end;
    end;
     if f[l,1]=2 then
    begin
      kh:=f[l,0]-m;
      if (b[kh mod m,kh div m+1]) and (fb[f[l,0],3]) then
      begin
        inc(t);
        fb[f[l,0],3]:=false;
        f[t,0]:=f[l,0];
        f[t,1]:=3;
        v[t]:=v[l]+2;
           if (f[t,0]=tx+(ty-1)*m) and (v[t]<num2) then num2:=v[t];
      end;
      kh:=f[l,1]+m;
      if (b[kh mod m,kh div m+1])and (fb[f[l,0],4]) then
      begin
        inc(t);
        fb[f[l,0],4]:=false;
        f[t,0]:=f[l,0];
        f[t,1]:=4;
        v[t]:=v[l]+2;
           if (f[t,0]=tx+(ty-1)*m) and (v[t]<num2) then num2:=v[t];
      end;
      if (fb[f[l,0]+1,1]) then
      begin
        inc(t);
        fb[f[l,0]+1,1]:=false;
        f[t,0]:=f[l,0]+1;
        f[t,1]:=1;
        v[t]:=v[l]+1;
           if (f[t,0]=tx+(ty-1)*m) and (v[t]<num2) then num2:=v[t];
      end;
    end;
     if f[l,1]=3 then
    begin
      kh:=f[l,0]-1;
      if (b[kh mod m,kh div m+1]) and (fb[f[l,0],1]) then
      begin
        inc(t);
        fb[f[l,0],1]:=false;
        f[t,0]:=f[l,0];
        f[t,1]:=1;
        v[t]:=v[l]+2;
           if (f[t,0]=tx+(ty-1)*m) and (v[t]<num2) then num2:=v[t];
      end;
      kh:=f[l,1]+1;
      if (b[kh mod m,kh div m+1])and (fb[f[l,0],2]) then
      begin
        inc(t);
        fb[f[l,0],2]:=false;
        f[t,0]:=f[l,0];
        f[t,1]:=2;
        v[t]:=v[l]+2;
           if (f[t,0]=tx+(ty-1)*m) and (v[t]<num2) then num2:=v[t];
      end;
      if (fb[f[l,0]+m,4]) then
      begin
        inc(t);
        fb[f[l,0]+m,4]:=false;
        f[t,0]:=f[l,0]+m;
        f[t,1]:=4;
        v[t]:=v[l]+1;
           if (f[t,0]=tx+(ty-1)*m) and (v[t]<num2) then num2:=v[t];
      end;
    end;
      if f[l,1]=4 then
      begin
      kh:=f[l,0]-1;
      if (b[kh mod m,kh div m+1]) and (fb[f[l,0],1]) then
      begin
        inc(t);
        fb[f[l,0],1]:=false;
        f[t,0]:=f[l,0];
        f[t,1]:=1;
        v[t]:=v[l]+2;
           if (f[t,0]=tx+(ty-1)*m) and (v[t]<num2) then num2:=v[t];
      end;
      kh:=f[l,1]+1;
      if (b[kh mod m,kh div m+1])and (fb[f[l,0],2]) then
      begin
        inc(t);
        fb[f[l,0],2]:=false;
        f[t,0]:=f[l,0];
        f[t,1]:=2;
        v[t]:=v[l]+2;
           if (f[t,0]=tx+(ty-1)*m) and (v[t]<num2) then num2:=v[t];
      end;
      if (fb[f[l,0]-m,3]) then
      begin
        inc(t);
        fb[f[l,0]-m,3]:=false;
        f[t,0]:=f[l,0]-m;
        f[t,1]:=3;
        v[t]:=v[l]+1;
           if (f[t,0]=tx+(ty-1)*m) and (v[t]<num2) then num2:=v[t];
      end;
    end;
  end;
end;


begin
  assign(input,'puzzle.in');
  assign(output,'puzzle.out');
  reset(input);
  rewrite(output);
  fillchar(b,sizeof(b),false);
   fillchar(bb,sizeof(bb),false);
  readln(n,m,q);
  for i:=1 to n do
  for j:=1 to m do
   begin
    read(x);
    if x=1 then
    begin
      b[j,i]:=true;
      bb[j,i]:=true;
    end;
   end;
  for i:=1 to q do
  begin
    ans:=100000;
    readln(ey,ex,sy,sx,ty,tx);
    if bb[sx-1,sy] then
    begin
      dfs(ex+(ey-1)*m,(sx-1)+(sy-1)*m);
      bfs((sx-1)+(sy-1)*m,1);
      if (num2<100000) and (num2+num<ans) then
      begin
        ans:=num2+num;
      end;
    end;
    if bb[sx+1,sy] then
    begin
      dfs(ex+(ey-1)*m,(sx+1)+(sy-1)*m);
       bfs((sx+1)+(sy-1)*m,1);
        if (num2<100000) and (num2+num<ans) then
      begin
        ans:=num2+num;
      end;
    end;
    if bb[sx,sy-1] then
    begin
      dfs(ex+(ey-1)*m,(sx)+(sy-2)*m);
       bfs((sx)+(sy-2)*m,1);
        if (num2<100000) and (num2+num<ans) then
      begin
        ans:=num2+num;
      end;
    end;
    if bb[sx,sy+1] then
    begin
      dfs(ex+(ey-1)*m,(sx)+(sy)*m);
       bfs((sx)+(sy)*m,1);
        if (num2<100000) and (num2+num<ans) then
      begin
        ans:=num2+num;
      end;
    end;
    if ans<100000 then writeln(ans) else writeln(-1);
  end;
  close(input);
  close(output);
end.
