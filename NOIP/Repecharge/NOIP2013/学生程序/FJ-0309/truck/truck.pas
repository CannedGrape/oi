program jk;
var i,j,p,x1,y1,k,ans,n,m,t:longint;
    x,y,z:array[0..50000]of longint;
    b,bo:array[0..10000]of boolean;
  function min(n,m:longint):longint;
    begin if n>m then exit(m) else exit(n); end;
  procedure bfs(q:longint);
  var f,r,i:longint;
      p,dis:array[0..10000]of longint;
    begin
      fillchar(dis,sizeof(dis),$7f);
      f:=1;r:=0;p[1]:=q;dis[1]:=9999999;
      repeat
        inc(r);
        for i:=1 to k do
          if (x[i]=p[r])and(z[i]<>0)and(bo[y[i]]) then
            begin
              inc(f);
              p[f]:=y[i];
              dis[f]:=min(dis[r],z[i]);
              bo[y[i]]:=false;
              if y[i]=y1 then begin ans:=dis[f];exit; end;
            end
          else
            if (y[i]=p[r])and(z[i]<>0)and(bo[x[i]]) then
              begin
                inc(f);
                p[f]:=x[i];
                bo[x[i]]:=false;
                dis[f]:=min(dis[r],z[i]);
                if x[i]=y1 then begin ans:=dis[f];exit; end;
              end;
     until f=r;
    end;
  procedure sort(r,l:longint);
  var t,mid,i,j:longint;
    begin
      i:=l;j:=r;mid:=z[(i+j)shr 1];
      repeat
        while z[i]>mid do inc(i);
        while z[j]<mid do dec(j);
        if i<=j then
          begin
            t:=z[i];z[i]:=z[j];z[j]:=t;
            t:=x[i];x[i]:=x[j];x[j]:=t;
            t:=y[i];y[i]:=y[j];y[j]:=t;
            inc(i);dec(j);
          end;
      until i>j;
      if i<r then sort(i,r);
      if j<l then sort(l,j);
    end;
  begin
    assign(input,'truck.in');reset(input);
    assign(output,'truck.out');rewrite(output);
    read(n,m);
    fillchar(b,sizeof(b),true);
    for i:=1 to m do
      begin read(x[i],y[i],z[i]); end;
    sort(1,m);
    b[x[1]]:=false;b[y[1]]:=false;t:=1;
    for i:=2 to m do
      begin
        if (b[x[i]])and(b[y[i]]=false) then
          begin b[x[i]]:=false;inc(t); end
        else
          if (b[x[i]]=false)and(b[y[i]]) then
            begin b[y[i]]:=false;inc(t); end
        else z[i]:=0;
        if t=n-1 then break;
      end;
    read(p);k:=i;
    for i:=1 to p do
      begin
        read(x1,y1);
        if (b[x1])or(b[y1]) then begin writeln('-1');continue; end;
        fillchar(bo,sizeof(bo),true);
        bo[x1]:=false;
        bfs(x1);
        writeln(ans);
      end;
    close(input);close(output);
  end.
