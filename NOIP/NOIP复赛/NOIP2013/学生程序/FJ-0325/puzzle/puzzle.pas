var g:array[0..31,0..31]of longint;
    w:array[0..10000,0..31,0..31]of longint;
    f,d:array[0..10000,0..2]of longint;
    i,j,n,m,q,ex,ey,sx,sy,tx,ty,ans,tot,x,y,s,t,temp,num,k:longint;
    zz:boolean;
    z:array[1..4,1..2]of longint=((1,0),(0,1),(-1,0),(0,-1));
begin
  assign(input,'puzzle.in');  reset(input);
  assign(output,'puzzle.out');  rewrite(output);
  readln(n,m,q);
  for i:=1 to n do
    begin
      for j:=1 to m do read(g[i,j]);
      readln;
    end;
  for i:=1 to q do
    begin
      readln(ex,ey,sx,sy,tx,ty);
      ans:=maxlongint; tot:=0;
      fillchar(f,sizeof(f),0);
      fillchar(w,sizeof(w),0);
      s:=1; t:=0; d:=f;
      f[1,1]:=ex; f[1,2]:=ey;
      w[1]:=g; w[1,sx,sy]:=2;
      while s>t do
        begin
          inc(t); t:=t mod 10000;
          for j:=1 to 4 do
            begin
              x:=f[t,1]+z[j,1];
              y:=f[t,2]+z[j,2];
              if (x>0)and(x<=n)and(y>0)and(y<=m)and(w[t,x,y]<>0) then
                begin
                  inc(s); s:=s mod 10000;
                  w[s]:=w[t];
                  w[s,f[t,1],f[t,2]]:=w[s,x,y];
                  w[s,x,y]:=1;
                  f[s,1]:=x; f[s,2]:=y; f[s,0]:=f[t,0]+1;
                  if w[s,tx,ty]=2 then
                    begin
                      if f[s,0]<ans then ans:=f[s,0];
                      dec(s); break;
                    end;
                  if f[s,0]>ans then dec(s);
                end;
            end;
        end;
      if ans=maxlongint then writeln(-1) else writeln(ans);
    end;
  close(input); close(output);
end.


