program match;
  var n,i,j,x,s,k,t:longint;
      a,c,b,d,e:array[1..100000] of longint;
begin
  assign(input,'match.in');assign(output,'match.out');reset(input);rewrite(output);
  read(n);s:=0;
  for i:=1 to n do begin
                     read(a[i]);d[a[i]]:=i;
                     end;
  for i:=1 to n do begin read(b[i]);e[b[i]]:=i;
                     end;
  x:=0;
  for i:=1 to n do if c[i]<>b[i] then x:=1;
  if x=0 then writeln(x) else begin
                                      for i:=1 to n do begin
                            k:=i;
        for j:=i+1 to n do if a[k]>a[j] then k:=j;
                               t:=a[i];a[i]:=a[k];a[k]:=t;
                               end;
                                      for i:=1 to n do begin
                            k:=i;
        for j:=i+1 to n do if b[k]>b[j] then k:=j;
                               t:=b[i];b[i]:=b[k];b[k]:=t;
                               end;
                                for i:=1 to n do s:=s+(abs(d[a[i]]-e[b[i]]));
                              if s<99999997 then writeln(s div 2) else
                              writeln((s div 2) mod 99999997);
                              end;

   close(input);close(output);
end.
