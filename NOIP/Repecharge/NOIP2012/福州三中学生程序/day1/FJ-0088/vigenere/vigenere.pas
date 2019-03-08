const filename='vigenere';
nums='abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ';
var n,m,i,j:longint;
map:array['A'..'z','A'..'z']of char;
ch1,ch2:char;
k:string;
s:ansistring;
begin
  for ch1:='A' to 'Z' do begin
    for ch2:='A' to 'Z' do
      map[ch1,ch2]:=chr(((ord(ch2)+ord(ch1)-65)-65)mod 26+65);
    for ch2:='a' to 'z' do
      map[ch1,ch2]:=chr(((ord(ch2)+ord(ch1)-97)-65)mod 26+65);
  end;
  for ch1:='a' to 'z' do begin
    for ch2:='A' to 'Z' do
      map[ch1,ch2]:=chr(((ord(ch2)+ord(ch1)-65)-97)mod 26+97);
    for ch2:='a' to 'z' do
      map[ch1,ch2]:=chr(((ord(ch2)+ord(ch1)-97)-97)mod 26+97);
  end;
  assign(input,filename+'.in');reset(input);
  assign(output,filename+'.out');rewrite(output);
  readln(k);
  readln(s);
  for i:=1 to length(s) do begin
    j:=1;
    while map[nums[j],k[(i-1)mod length(k)+1]]<>s[i] do inc(j);
    write(nums[j]);
  end;
  close(input);close(output);
end.
