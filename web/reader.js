// The Forge — Text-to-Speech Reader
// Uses the Web Speech API (built into modern browsers).
// Reads lesson content aloud, skipping code blocks.

(function() {
  if (!('speechSynthesis' in window)) return;

  const synth = window.speechSynthesis;
  let utterances = [];
  let currentIndex = -1;
  let isPlaying = false;
  let isPaused = false;
  let rate = 1.0;

  // Build the control bar
  const bar = document.createElement('div');
  bar.id = 'reader-bar';
  bar.innerHTML = `
    <button id="reader-play" title="Play">&#9654;</button>
    <button id="reader-pause" title="Pause" disabled>&#10074;&#10074;</button>
    <button id="reader-stop" title="Stop" disabled>&#9632;</button>
    <label title="Speed">
      <span>Speed</span>
      <select id="reader-speed">
        <option value="0.7">0.7x</option>
        <option value="0.85">0.85x</option>
        <option value="1" selected>1x</option>
        <option value="1.15">1.15x</option>
        <option value="1.3">1.3x</option>
        <option value="1.5">1.5x</option>
      </select>
    </label>
    <span id="reader-status"></span>
  `;
  document.body.appendChild(bar);

  const btnPlay = document.getElementById('reader-play');
  const btnPause = document.getElementById('reader-pause');
  const btnStop = document.getElementById('reader-stop');
  const selSpeed = document.getElementById('reader-speed');
  const status = document.getElementById('reader-status');

  // Collect readable elements from main content
  function collectText() {
    const main = document.querySelector('main');
    if (!main) return [];

    const elements = [];
    const walker = main.querySelectorAll(
      'h1, h2, h3, h4, p, li, .objective, dt, dd, summary'
    );

    walker.forEach(el => {
      // Skip elements inside code blocks, pre, download sections, nav, or hidden elements
      if (el.closest('pre, code, .chapter-downloads, nav, .progress-check, script, style, #reader-bar')) return;
      // Skip elements or ancestors that are hidden
      const closestHidden = el.closest('[style*="display:none"], [style*="display: none"]');
      if (closestHidden) return;
      if (window.getComputedStyle(el).display === 'none') return;
      // Skip empty elements
      const text = el.textContent.trim();
      if (!text) return;
      // Skip very short labels
      if (text === 'Completed') return;

      elements.push({ el: el, text: text });
    });

    return elements;
  }

  function clearHighlight() {
    document.querySelectorAll('.reader-highlight').forEach(el => {
      el.classList.remove('reader-highlight');
    });
  }

  function highlight(el) {
    clearHighlight();
    if (el) {
      el.classList.add('reader-highlight');
      el.scrollIntoView({ behavior: 'smooth', block: 'center' });
    }
  }

  function speakNext() {
    currentIndex++;
    if (currentIndex >= utterances.length) {
      stop();
      return;
    }

    const item = utterances[currentIndex];
    const utter = new SpeechSynthesisUtterance(item.text);
    utter.rate = rate;
    utter.onstart = () => {
      highlight(item.el);
      status.textContent = `${currentIndex + 1}/${utterances.length}`;
    };
    utter.onend = () => {
      if (isPlaying && !isPaused) {
        speakNext();
      }
    };
    utter.onerror = () => {
      if (isPlaying) speakNext();
    };

    synth.speak(utter);
  }

  function play() {
    if (isPaused) {
      synth.resume();
      isPaused = false;
      isPlaying = true;
      btnPlay.disabled = true;
      btnPause.disabled = false;
      btnStop.disabled = false;
      return;
    }

    synth.cancel();
    utterances = collectText();
    if (utterances.length === 0) return;

    currentIndex = -1;
    isPlaying = true;
    isPaused = false;
    btnPlay.disabled = true;
    btnPause.disabled = false;
    btnStop.disabled = false;

    speakNext();
  }

  function pause() {
    synth.pause();
    isPaused = true;
    isPlaying = false;
    btnPlay.disabled = false;
    btnPause.disabled = true;
  }

  function stop() {
    synth.cancel();
    isPlaying = false;
    isPaused = false;
    currentIndex = -1;
    clearHighlight();
    btnPlay.disabled = false;
    btnPause.disabled = true;
    btnStop.disabled = true;
    status.textContent = '';
  }

  btnPlay.addEventListener('click', play);
  btnPause.addEventListener('click', pause);
  btnStop.addEventListener('click', stop);
  selSpeed.addEventListener('change', () => {
    rate = parseFloat(selSpeed.value);
    // If currently playing, restart from current position
    if (isPlaying) {
      synth.cancel();
      currentIndex--;
      speakNext();
    }
  });

  // Stop speech when leaving the page
  window.addEventListener('beforeunload', () => synth.cancel());
})();
