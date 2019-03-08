var n,i,j,sum,ans:longint;
    h,hh:array[0..100001]of longint;
    f:boolean;
begin
  assign(input,'flower.in'); reset(input);
  assign(output,'flower.out'); rewrite(output);
  readln(n);
  sum:=n;
  if n=1 then
   begin
     writeln(1);
     close(input);
     close(output);
     halt;
   end;
  for i:=1 to n do
    begin
      read(h[i]);
      hh[i]:=h[i];
    end;
  i:=1;
  while (i<=sum)and(i*2+1<=sum)and(i*2-1>0) do
    begin
       f:=false;
       if (h[2*i]<h[2*i-1])or(h[2*i]<h[2*i+1]) then
        begin
          for j:=2*i to sum-1 do h[j]:=h[j+1];
          dec(sum);
          f:=true;
        end;
       if sum=1 then
          begin
            ans:=1;
            break;
          end;
       if not f then inc(i);
    end;
  sum:=n;
  i:=1;
  while (i<=sum)and(i*2+1<=sum)and(i*2-1>0) do
    begin
      f:=false;
      if (hh[2*i]>hh[2*i-1])or(hh[2*i]>hh[2*i+1]) then
        begin
          for j:=2*i to sum-1 do hh[j]:=hh[j+1];
          dec(sum);
          f:=true;
        end;
       if sum=1 then
          begin
            ans:=1;
            break;
          end;
      if not f then inc(i);
    end;
  if sum>ans then ans:=sum;
  writeln(ans);
  close(input);
  close(output);
end.
