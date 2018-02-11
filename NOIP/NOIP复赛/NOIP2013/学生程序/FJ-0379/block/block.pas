var h:array[1..100000] of longint;
    n,i,t:longint;
  procedure q(a,b:longint);
    var x,y:longint;
    begin
      if a=b then t:=t+h[a] else begin
        x:=h[a];
        for i:=a to b do if h[i]<x then x:=h[i];
        for i:=a to b do h[i]:=h[i]-x;
        t:=t+x;x:=0;y:=0;
        for i:=a to b do begin
          if (h[i]<>0) and (x=0) then x:=i;
          if (h[i+1]=0) and (x<>0) then y:=i;
          if (x<>0) and (y<>0) then begin
                                      q(x,y);
                                      x:=0;y:=0;
                                    end;
                               end;
         end;
         end;
begin
  assign(input,'block.in');assign(output,'block.out');
  reset(input);rewrite(output);
  read(n);t:=0;
  for i:=1 to n do read(h[i]);
  q(1,n);
  writeln(t);
  close(input);close(output);
end.
