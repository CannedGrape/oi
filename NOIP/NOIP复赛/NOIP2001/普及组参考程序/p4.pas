const
  maxn = 30;
  maxv = 20000;
var
  i,k,n,v:integer;
  volume:array[1..maxn] of integer;
  h:array[0..maxv] of boolean;
  
  begin
  	read(v,n);
  	for i:=1 to n do read(volume[i]);
  	fillchar(h,sizeof(h),false);
  	h[0]:=true;
  	for i:=1 to n do
  	  for k:=v downto volume[i] do
  	    h[k]:=h[k] or h[k-volume[i]];  	
  	i:=v;
  	while( (i>0) and (not h[i]) ) do dec(i);
  	writeln(v-i);
  end.