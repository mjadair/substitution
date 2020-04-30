# substitution

<p>Implement a program that implements a substitution cipher, per the below.</p>

<div class="highlighter-rouge"><div class="highlight"><pre class="highlight"><code>$ ./substitution JTREKYAVOGDXPSNCUIZLFBMWHQ
plaintext:  HELLO
ciphertext: VKXXN
</code></pre></div></div>

<h2 id="background">Background</h2>

<p>In a substitution cipher, we “encrypt” (i.e., conceal in a reversible way) a message by replacing every letter with another letter. To do so, we use a <em>key</em>: in this case, a mapping of each of the letters of the alphabet to the letter it should correspond to when we encrypt it. To “decrypt” the message, the receiver of the message would need to know the key, so that they can reverse the process: translating the encrypt text (generally called <em>ciphertext</em>) back into the original message (generally called <em>plaintext</em>).</p>

<p>A key, for example, might be the string <code class="highlighter-rouge">NQXPOMAFTRHLZGECYJIUWSKDVB</code>. This 26-character key means that <code class="highlighter-rouge">A</code> (the first letter of the alphabet) should be converted into <code class="highlighter-rouge">N</code> (the first character of the key), <code class="highlighter-rouge">B</code> (the second letter of the alphabet) should be converted into <code class="highlighter-rouge">Q</code> (the second character of the key), and so forth.</p>

<p>A message like <code class="highlighter-rouge">HELLO</code>, then, would be encrypted as <code class="highlighter-rouge">FOLLE</code>, replacing each of the letters according to the mapping determined by the key.</p>

<p>Let’s write a program called <code class="highlighter-rouge">substitution</code> that enables you to encrypt messages using a substitution cipher. At the time the user executes the program, they should decide, by providing a command-line argument, on what the key should be in the secret message they’ll provide at runtime.</p>

<p>Here are a few examples of how the program might work. For example, if the user inputs a key of <code class="highlighter-rouge">YTNSHKVEFXRBAUQZCLWDMIPGJO</code> and a plaintext of <code class="highlighter-rouge">HELLO</code>:</p>

<div class="highlighter-rouge"><div class="highlight"><pre class="highlight"><code>$ ./substitution YTNSHKVEFXRBAUQZCLWDMIPGJO
plaintext:  HELLO
ciphertext: EHBBQ
</code></pre></div></div>

<p>Here’s how the program might work if the user provides a key of <code class="highlighter-rouge">VCHPRZGJNTLSKFBDQWAXEUYMOI</code> and a plaintext of <code class="highlighter-rouge">hello, world</code>:</p>

<div class="highlighter-rouge"><div class="highlight"><pre class="highlight"><code>$ ./substitution VCHPRZGJNTLSKFBDQWAXEUYMOI
plaintext:  hello, world
ciphertext: jrssb, ybwsp
</code></pre></div></div>

<p>Notice that neither the comma nor the space were substituted by the cipher. Only substitute alphabetical characters! Notice, too, that the case of the original message has been preserved. Lowercase letters remain lowercase, and uppercase letters remain uppercase.</p>

<p>Whether the characters in the key itself are uppercase or lowercase doesn’t matter. A key of <code class="highlighter-rouge">VCHPRZGJNTLSKFBDQWAXEUYMOI</code> is functionally identical to a key of <code class="highlighter-rouge">vchprzgjntlskfbdqwaxeuymoi</code> (as is, for that matter, <code class="highlighter-rouge">VcHpRzGjNtLsKfBdQwAxEuYmOi</code>).</p>

<p>And what if a user doesn’t provide a valid key?</p>

<div class="highlighter-rouge"><div class="highlight"><pre class="highlight"><code>$ ./substitution ABC
Key must contain 26 characters.
</code></pre></div></div>

<p>Or really doesn’t cooperate?</p>

<div class="highlighter-rouge"><div class="highlight"><pre class="highlight"><code>$ ./substitution
Usage: ./substitution key
</code></pre></div></div>

<p>Or even…</p>

<div class="highlighter-rouge"><div class="highlight"><pre class="highlight"><code>$ ./substitution 1 2 3
Usage: ./substitution key
</code></pre></div></div>

<h2 id="specification">Specification</h2>

<p>Design and implement a program, <code class="highlighter-rouge">substitution</code>, that encrypts messages using a substitution cipher.</p>

<ul>
  <li data-marker="*">Implement your program in a file called <code class="highlighter-rouge">substitution.c</code> in a directory called `substitution.</li>
  <li data-marker="*">Your program must accept a single command-line argument, the key to use for the substitution. The key itself should be case-insensitive, so whether any character in the key is uppercase or lowercase should not affect the behavior of your program.</li>
  <li data-marker="*">If your program is executed without any command-line arguments or with more than one command-line argument, your program should print an error message of your choice (with <code class="highlighter-rouge">printf</code>) and return from <code class="highlighter-rouge">main</code> a value of <code class="highlighter-rouge">1</code> (which tends to signify an error) immediately.</li>
  <li data-marker="*">If the key is invalid (as by not containing 26 characters, containing any character that is not an alphabetic character, or not containing each letter exactly once), your program should print an error message of your choice (with <code class="highlighter-rouge">printf</code>) and return from <code class="highlighter-rouge">main</code> a value of <code class="highlighter-rouge">1</code> immediately.</li>
  <li data-marker="*">Your program must output <code class="highlighter-rouge">plaintext:</code> (without a newline) and then prompt the user for a <code class="highlighter-rouge">string</code> of plaintext (using <code class="highlighter-rouge">get_string</code>).</li>
  <li data-marker="*">Your program must output <code class="highlighter-rouge">ciphertext:</code> (without a newline) followed by the plaintext’s corresponding ciphertext, with each alphabetical character in the plaintext substituted for the corresponding character in the ciphertext; non-alphabetical characters should be outputted unchanged.</li>
  <li data-marker="*">Your program must preserve case: capitalized letters must remain capitalized letters; lowercase letters must remain lowercase letters.</li>
  <li data-marker="*">After outputting ciphertext, you should print a newline. Your program should then exit by returning <code class="highlighter-rouge">0</code> from <code class="highlighter-rouge">main</code>.</li>
</ul>




