var fx:array[1..4]of integer=(1,0,-1,0);
    fy:array[1..4]of integer=(0,1,0,-1);
    a:array[0..31,0..31]of longint;
    u:array[0..31,0..31]of boolean;
    b,d:array[0..1000,1..2]of longint;
    c:array[0..1000]of longint;
    i,j,n,m,q,t,s,x1,x2,x3,x4,y1,y2,y3,y4:longint;bo:boolean;
begin
  assign(input,'puzzle.in');reset(input);
  assign(output,'puzzle.out');rewrite(output);
    readln(n,m,q);
    for i:=1 to n do
    begin
      for j:=1 to m do read(a[i,j]);readln;
    end;
    for i:=1 to q do
    begin
      readln(x1,y1,x2,y2,x3,y3);
      if (x2=x3)and(y2=y3) then writeln(0)
      else if a[x1,y1]=0 then writeln(-1)
      else
      begin
        fillchar(u,sizeof(u),true);
        d[1,1]:=x2;d[1,2]:=y2;c[1]:=0;
        b[1,1]:=x1;b[1,2]:=y1;u[x1,y1]:=false;
        t:=0;s:=1;bo:=false;
        repeat
          inc(t);
          for j:=1 to 4 do
          begin
            x4:=b[t,1]+fx[j];y4:=b[t,2]+fy[j];
            if (a[x4,y4]=1)and(u[x4,y4]) then
            begin
              inc(s);u[x4,y4]:=false;
              b[s,1]:=x4;b[s,2]:=y4;c[s]:=c[t]+1;
              if (x4=d[t,1])and(y4=d[t,2]) then
              begin
                d[s,1]:=b[t,1];d[s,2]:=b[t,2];
              end else d[s]:=d[t];
              if (d[s,1]=x3)and(d[s,2]=y3) then
              begin
                bo:=true;break;
              end;
            end;
          end;
        until (t=s)or(bo);
        if bo then writeln(c[s]) else writeln(-1);
      end;
    end;
  close(input);close(output);
end.
