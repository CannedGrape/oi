program Level;

var a,b:array[1..2000] of longint;
    i,j,n,m,t,x,y,k:longint;
begin
  assign(input,'level.in');reset(input);
  assign(output,'level.out');rewrite(output);

  readln(n,m);

  fillchar(a,sizeof(a),0);fillchar(b,sizeof(b),0);
  read(x);t:=1;
  for i:=1 to x do begin
    read(b[i]);
    inc(a[b[i]]);
  end;readln;
  for i:=2 to m do begin
    read(x);read(b[1]);
    if a[b[1]]>0 then begin
      inc(a[b[1]]);
      for j:=2 to x do begin
        read(b[j]);
        if a[b[j]]<a[b[j-1]] then a[b[j]]:=a[b[j-1]]
          else inc(a[b[j]]);
      end;
    end else begin
          for j:=2 to x do begin
            read(b[j]);
            if a[b[j]]=0 then a[b[j]]:=a[b[1]];
          end;
        end;
  end;

  t:=0;
  for i:=1 to n do
    if a[i]>t then t:=a[i];
  writeln(t);

  close(input);close(output);
end.
