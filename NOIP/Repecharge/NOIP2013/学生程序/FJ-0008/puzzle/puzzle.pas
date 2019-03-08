var k,head,tail,s,s1,x1,y1,ex,ey,sx,sy,tx,ty,n,m,p,i,j,l,a:longint;o:string;b:array[1..30]of string;
c:array[1..100000,0..30]of string;x,y,f:array[1..100000]of longint;t1:char;
e:array[1..4]of integer=(1,0,-1,0);d:array[1..4]of integer=(0,1,0,-1);
ans:array[1..500]of longint;
begin
assign(input,'puzzle.in');reset(input);
assign(output,'puzzle.out');rewrite(output);
        read(n,m,p);
        for i:=1 to n do  begin
         for j:=1 to m do
         begin
          read(a);
          str(a,o);
          b[i]:=b[i]+o;
         end; readln;end;
        for i:=1 to p do
         begin
           read(ex,ey,sx,sy,tx,ty);
           for j:=1 to n do
            c[1,j]:=b[j];
           c[1,ex][ey]:='2';
           c[1,sx][sy]:='3';
           head:=1;tail:=1;
           x[1]:=ex;y[1]:=ey; s1:=0;
           repeat
              if c[head,tx][ty]='3' then begin ans[i]:=f[head];s1:=-1;break;end;
                for j:=1 to 4 do
                 begin
                  x1:=x[head]+e[j];
                  y1:=y[head]+d[j];
                  if (x1>0)and(x1<=n)and(y1>0)and(y1<=m)and(c[head,x1][y1]<>'0')then
                  begin
                    inc(tail);
                    for l:=1 to n do
                    c[tail,l]:=c[head,l];
                    t1:=c[tail,x1][y1];
                    c[tail,x1][y1]:='2';
                    c[tail,x[head]][y[head]]:=t1;
                    x[tail]:=x1;y[tail]:=y1;
                    f[tail]:=f[head]+1;
                  for l:=1 to tail-1 do
                   begin
                     s:=-1;
                     for k:=1 to n do
                      if c[l,k]<>c[tail,k]then
                      begin s:=1;break;end;
                   if s=-1 then begin dec(tail); break;end;
                  end;
                 end; end;
                 inc(head);
            until head>tail;
            if s1=0 then ans[i]:=-1;
           end;
        for i:=1 to p do
         writeln(ans[i]);
         close(input);close(output);
end.
