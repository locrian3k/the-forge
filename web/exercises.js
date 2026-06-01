// The Forge, Exercise Progress Tracker
// Uses localStorage to persist checkbox state across sessions.

document.addEventListener('DOMContentLoaded', () => {
  const STORAGE_KEY = 'forge-progress';

  // Load saved progress
  function loadProgress() {
    try {
      return JSON.parse(localStorage.getItem(STORAGE_KEY)) || {};
    } catch (e) {
      return {};
    }
  }

  // Save progress
  function saveProgress(progress) {
    localStorage.setItem(STORAGE_KEY, JSON.stringify(progress));
  }

  // Initialize all progress checkboxes
  const progress = loadProgress();
  document.querySelectorAll('.progress-check input[type="checkbox"]').forEach(cb => {
    const id = cb.dataset.exercise;
    if (!id) return;
    cb.checked = !!progress[id];
    cb.addEventListener('change', () => {
      const p = loadProgress();
      p[id] = cb.checked;
      saveProgress(p);
      updateProgressCount();
    });
  });

  // Update progress counter if present
  function updateProgressCount() {
    const counter = document.getElementById('progress-count');
    if (!counter) return;
    const p = loadProgress();
    const total = document.querySelectorAll('.progress-check input').length;
    const done = Object.values(p).filter(Boolean).length;
    counter.textContent = `${done}/${total}`;
  }

  updateProgressCount();

  // Highlight active sidebar link
  const currentPage = window.location.pathname.split('/').pop();
  document.querySelectorAll('nav.sidebar a').forEach(link => {
    if (link.getAttribute('href') === currentPage ||
        link.getAttribute('href') === 'chapters/' + currentPage) {
      link.classList.add('active');
    }
  });
});
