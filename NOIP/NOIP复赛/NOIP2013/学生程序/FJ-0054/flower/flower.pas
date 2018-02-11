var
    fu,fd,du,dd,h,pu,pd,wu,wd:array[0..200000] of longint;
    n,i,j,ansmax,o,k:longint;
function max(a,b:longint):longint;
begin
  if a>b then exit(a);exit(b);
end;
begin
     assign(input,'flower.in');reset(input);
   assign(output,'flower.out');rewrite(output);
    readln(n);
    for i:=1 to n do read(h[i]); ansmax:=1;
    for i:=1 to n do begin fu[i]:=1;fd[i]:=1;wu[i]:=i;wd[i]:=i;end;
    for i:=2 to n do
     for j:=1 to i-1 do
      begin
         if h[i]>h[j] then
         begin
           if fu[i]<fd[j]+1 then
             begin
               fu[i]:=fd[j]+1;
               wu[i]:=wd[j];
             end
           else
             if fu[i]=fd[j]+1 then
               if wu[i]<wd[j] then
               wu[i]:=wd[j];
         end;
         if h[i]<h[j] then
           begin
             if fd[i]<fu[j]+1 then
               begin
                 fd[i]:=fu[j]+1;
                 wd[i]:= wu[j];
               end
             else if fd[i]=fu[j]+1 then
              if wd[i]<wu[j] then
               wd[i]:=wu[j];
           end;
      end;
    for i:=1 to n do
      begin
         o:=wd[i];
         if o-1<fd[i] then ansmax:=max(ansmax,fd[i])
         else
         begin
           for j:=o-1 downto 0 do
             if h[j]<h[o] then break;
         if j=0 then ansmax:=max(ansmax,fd[i])
         else
           if j>=fd[i] then ansmax:=max(ansmax,fd[i]*2)
           else ansmax:=max(ansmax,j+fd[i]);
         end;
        o:=wu[i];
         if o-1<fu[i] then ansmax:=max(ansmax,fu[i])
         else
        begin
           for j:=o-1 downto 0 do
             if h[j]>h[o] then break;
           if j=0 then ansmax:=max(ansmax,fu[i])
           else
           if j>=i-o+1 then ansmax:=max(ansmax,fu[i]*2)
           else ansmax:=max(ansmax,j+fu[i]);
        end;
      end;  writeln(ansmax);
    close(input);close(output);
end.
