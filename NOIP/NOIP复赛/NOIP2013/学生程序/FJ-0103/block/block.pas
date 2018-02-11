var i,j,n,ans,max,l,length,k:longint;
    h:array[0..100001] of longint;
    t,u,d:boolean;

procedure up(i:longint);
begin
  if h[i]<>0 then
    begin
      if h[i]>=h[i-1] then
        begin
          inc(l);
          up(i+1);
        end
      else begin l:=-1; exit; end;
    end;
end;

procedure down(i:longint);
begin
  if h[i]<>0 then
    begin
      if h[i]<=h[i-1] then
        begin
          inc(l);
          down(i+1);
        end
      else begin l:=-1; exit; end;
    end;
end;


begin
  assign(input,'block.in');
  assign(output,'block.out');
  reset(input);
  rewrite(output);
  readln(n);
  max:=0;
  fillchar(h,sizeof(h),0);
  u:=true;
  d:=true;
  for i:=1 to n do
    begin
      read(h[i]);
      if h[i]>max then max:=h[i];
      if u and (h[i]<h[i-1]) and (i<>1) then u:=false;
      if d and (h[i]>h[i-1]) and (i<>1) then d:=false;
    end;
  if u or d then
    if u then writeln (h[n]) else writeln (h[1]);
  if (not u) and (not d) then
    begin
      ans:=0;
      for i:=1 to max do
        begin
          t:=false;
          j:=1;
          while j<=n do
            begin
              if (h[j-1]=0) and (h[j]>0) then
                begin
                  length:=0;
                  l:=0;
                  up(j);
                  if length<l then length:=l;
                  if (length>0) then
                    begin
                      ans:=ans+h[j+length-1];
                      for k:=j to j+length-1 do h[k]:=0;
                      j:=j+length;
                    end;
                  length:=0;
                  l:=0;
                  down(j);
                  if length<l then length:=l;
                  if (length>0) then
                    begin
                      ans:=ans+h[j];
                      for k:=j to j+length-1 do h[k]:=0;
                      j:=j+length;
                    end;
                end;
              if length=0 then
                begin
                  while h[j]>0 do
                    begin
                      dec(h[j]);
                      inc(j);
                      t:=true;
                    end;
                  if t then
                    begin
                      inc(ans);
                      t:=false;
                    end;
                end;
              if j<=n then inc(j);
            end;
        end;
      writeln(ans);
    end;
  close(input);
  close(output);
end.
