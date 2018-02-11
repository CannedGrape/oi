var n,m,q1,i,j,s,head,tail,min,ex,ey,sx,sy,tx,ty,ans:longint;
  pd:boolean;
  a,b:array[0..31,0..31]of boolean;
  p:array[1..4] of longint=(-1,1,0,0);
  q:array[1..4] of longint=(0,0,-1,1);
  x,y,fa,d:array[0..10000]of longint;
  aa,c:array[0..31,0..31]of longint;
  procedure dfs(x1,y1,x2,y2,z:longint);
    var i:longint;
    begin
      if (not a[x1,y1])or(b[x1,y1]) then exit;
      b[x1,y1]:=true;
      if (x1=x2)and(y1=y2) then
        begin
          if z<min then min:=z;
          exit;
        end;
      for i:=1 to 4 do dfs(x1+p[i],y1+q[i],x2,y2,z+1);
    end;
  begin
    assign(input,'puzzle.in');reset(input);
    assign(output,'puzzle.out');rewrite(output);
    readln(n,m,q1);
    for i:=1 to n do
      begin
        for j:=1 to m do
          begin
            read(aa[i,j]);
            if aa[i,j]=1 then a[i,j]:=true;
          end;
        readln;
      end;
    for i:=1 to q1 do
      begin
        readln(ex,ey,sx,sy,tx,ty);
        fillchar(x,sizeof(x),0);
        fillchar(y,sizeof(y),0);
        fillchar(b,sizeof(b),false);
        fillchar(c,sizeof(c),0);
        fillchar(fa,sizeof(fa),0);
        fillchar(d,sizeof(d),0);
        head:=1; tail:=1;
        x[head]:=sx; y[head]:=sy;
        while head<=tail do
          begin
            for j:=1 to 4 do
              if (a[x[head]+p[j],y[head]+q[j]])and(not b[x[head]+p[j],y[head]+q[j]]) then
                begin
                  inc(tail);
                  x[tail]:=x[head]+p[j];
                  y[tail]:=y[head]+q[j];
                  b[x[tail],y[tail]]:=true;
                  c[x[tail],y[tail]]:=c[x[head],y[head]]+1;
                  fa[tail]:=head;
                  if b[tx,ty] then
                    begin
                      inc(d[0]);
                      d[d[0]]:=tail;
                      s:=fa[tail];
                      while s<>0 do
                        begin
                          inc(d[0]);
                          d[d[0]]:=s;
                          s:=fa[s];
                        end;
                      break;
                    end;
                end;
            inc(head);
            if b[tx,ty] then break;
          end;
        ans:=0; pd:=false;
        for j:=d[0]-1 downto 1 do
          begin
            min:=maxlongint;
            fillchar(b,sizeof(b),false);
            a[x[d[j+1]],y[d[j+1]]]:=true;
            dfs(ex,ey,x[d[j]],y[d[j]],0);
            a[x[d[j+1]],y[d[j+1]]]:=false;
            ex:=x[d[j]]; ey:=y[d[j]];
            if min=maxlongint then
              begin
                writeln(-1);
                pd:=true;
                break;
              end;
            ans:=ans+1+min;
          end;
        if pd then continue;
        writeln(ans);
      end;
    close(input);
    close(output);
  end.
