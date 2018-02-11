program flower;

var  lmax,k,n,i:longint;
     h,g:array[-100..101000] of longint;
     flaga,flagb:boolean;

  procedure work(x:longint);
    var a:longint ;

    begin
        k:=k+1;
        g[k]:=h[x];
        if k>lmax then if odd(k) then lmax:=k
                                 else lmax:=k-1;
        if flaga then if odd(k) then for a:=(x+1) to n do
                                         begin
                                             if h[a]>g[k] then work(a);
                                         end
                                else for a:=(x+1) to n do
                                         begin
                                             if h[a] <g[k] then work(a);
                                         end;
        if flagb then if odd(k) then for a:=(x+1) to n do
                                         begin
                                             if h[a]<g[k] then work(a);
                                         end
                                else for a:=(x+1) to n do
                                         begin
                                             if h[a]>g[k] then work(a);
                                         end;

        g[k]:=0;
        k:=k-1;
    end;




begin
assign(input,'flower.in');
reset(input);
assign(output,'flower.out');
rewrite(output);

read(n);
for i:=1 to n do read(h[i]);

for i:=1 to n-1 do
  begin
    fillchar(g,sizeof(g),0);
    k:=1;
    g[k]:=h[i];
    flaga:=false; flagb:=false;
    if g[k]<h[i+1]  then  flaga:=true;
    if g[k]>h[i+1]  then  flagb:=true;

    if flaga or flagb then  work(i+1)
                      else  if n<=(n-2) then work(i+2);

  end;

writeln(lmax);

close(input);
close(output);
end.
