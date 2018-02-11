program flower;
var n,a,b,c,l,s1,s2:longint;
h,h1,h2:array[-1..100001] of longint;

begin
assign(input,'flower.in');
assign(output,'flower.out');
reset(input);rewrite(output);
readln(n);

fillchar(h,sizeof(h),0);
fillchar(h1,sizeof(h1),0);
fillchar(h2,sizeof(h2),0);

for a:=1 to n do read(h[a]);
if n=1 then begin write(n);close(input);close(output);halt;end;
if n=2 then begin
  if h[1]<>h[2] then begin
    write('2');close(input);close(output);halt;end
  else begin write('1');close(input);close(output);halt;end;end;


l:=1;
s1:=1;
h1[0]:=maxlongint;


while l<=n do begin
  if s1 mod 2<>0 then begin
     while ((h[l]>=h[l+1]) or (h[l]>=h1[s2-1])) and (l<n) do inc(l);
     if l>=n then begin
          l:=n+1;
          if h[n]<h1[s1-1] then break
                        else begin dec(s1);break;end;
       end
       else begin
         h1[s1]:=h[l];
         inc(l);
         inc(s1);
     end
  end
  else begin
    while ((h[l]<=h[l+1]) or (h[l]<=h1[s1-1])) and (l<n) do inc(l);
    if l>=n then begin
          l:=n+1;
          if h[n]>h1[s1-1] then break
                           else begin dec(s1);break;end;
    end
    else begin
        h1[s1]:=h[l];
        inc(l);
        inc(s1);
      end;
    end;
end;

s2:=1;l:=1;h2[0]:=0;

while l<=n do begin
  if s2 mod 2<>0 then begin
     while ((h[l]<=h[l+1]) or (h[l]<=h2[s2-1])) and (l<n) do inc(l);
     if l>=n then begin
        l:=n+1;
        if h[n]>h2[s2-1] then break
                             else begin dec(s2);break;end;
     end
     else begin
       h2[s2]:=h[l];
       inc(s2);
       inc(l);
     end;
  end
  else begin
    while ((h[l]>=h[l+1]) or (h[l]>=h2[s2-1])) and (l<n) do inc(l);
    if l>=n then begin
       l:=n+1;
       if h[n]<h2[s2-1] then break
                        else begin dec(s2);break;end;
    end
    else begin
       h2[s2]:=h[l];
       inc(l);
       inc(s2);
      end;
  end;

end;


if s1<s2 then write(s2) else write(s1);

close(input);
close(output);
end.
